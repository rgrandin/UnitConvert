/**
 * @file main.cpp
 * @author 	Robert Grandin
 * @date 23 June 2011
 *
 * @section Class Description & Notes
 *
 * This is the main file required for the unit conversion program.
 *
 *
 * All functions contained within this program are intended for use with the GNU
 * C++ compiler (g++).  Use with other compilers may produce unexpected results
 * and such use is at the users' own risk.
 *
 *
 * @section Revisions
 *
 * @date 23 June 2011
 *	- Creation date.
 *
 *
 *
 *
 * @section License
 *
 * Copyright (c) 2011, Robert Grandin
 * All rights reserved.
 *
 * Redistribution and use of this file is permitted provided that the following
 * conditions are met:
 * 	-# 	Redistributions must produce the above copyright notice, this list of
 * 		conditions, and the following disclaimer in the documentation and/or
 * 		other materials provided with the distribution.
 * 	-#	Neither the name of the organization nor the names of its contributors
 * 		may be used to endorse or promote products derived from this software
 * 		without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY COPYRIGHT HOLDER "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT
 * LIMITING TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *
 */


// ==== INCLUDE FILES ======================================================
#include <iostream>
using namespace std;
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cmath>
#include <memory>
#include <time.h>
#include <sigc++/retype_return.h>
#include <glibmm.h>
#include <glibmm/exception.h>
#include <gtkmm.h>
#include "GUIUnitConvert.h"

/*
 * INCLUDE STRING-DEFINITION OF GUI.  THIS IS BASED ON THE GLADE-GENERATED FILE
 * AND ITS GENERATION IS ASSISTED BY THE genstringinterface.sh SHELL SCRIPT.
 * THIS SCRIPT SIMPLY ADDS A VARIABLE DECLARATION TO THE HEAD OF THE FILE AND
 * INSERTS THE NECESSARY ESCAPE CHARACTERS TO ALLOW FOR QUOTATION MARKS AND
 * NEWLINES IN THE INTERFACE DEFINITION STRING.
 */
#include "ui/interface.ui"


int main(int argc, char *argv[])
{
	/*
	 * PREPARE FOR THREADS
	 */
	if(!Glib::thread_supported()) Glib::thread_init();
	//Glib::init();

	// PREPARE FOR THE GUI
	Gtk::Main kit(argc,argv);

	/*
	 * THE FOLLOWING SECTION CREATES THE Gtk::Builder OBJECT FOR THE GUI AND
	 * LOADS GLADE FILE.  THE GLADE FILE IS TREATED AS A "DERIVED WIDGET".  IF
	 * THE GLADE FILE IS LOADED DIRECTLY (BY PLACING THE add_from_file() IN THE
	 * CLASS DEFINITION AND RUNNING THE INSTANCE OF THE CLASS HERE IN main()),
	 * A SMALL BLANK WINDOW WILL APPEAR IN ADDITION TO THE DESIRED GUI.  MY
	 * INTERFACE IS DERIVED FROM Gtk::Window, AND IS LOADED AS SUCH.
	 *
	 * FOR MORE INFO:
	 * http://library.gnome.org/devel/gtkmm-tutorial/2.21/sec-builder-using-derived-widgets.html.en
	 *
	 */
	Glib::RefPtr<Gtk::Builder> xml_interface = Gtk::Builder::create();
	try
	{
		//xml_interface->add_from_file("../ui/LaminographyRecon.ui");
		xml_interface->add_from_string(glade_xml);
	}
	catch(const Glib::FileError& ex)
	{
		std::cerr << "FileError: " << ex.what() << std::endl;
		return 1;
	}
	catch(const Gtk::BuilderError& ex)
	{
		std::cerr << "BuilderError: " << ex.what() << std::endl;
		return 1;
	}


	/*
	 * RUN GUI PROGRAM IF NO COMMAND-LINE ARGUMENTS PROVIDED
	 */
	if(argc == 1){
		GUIUnitConvert *recon_window = 0;
		xml_interface->get_widget_derived("window_main",recon_window);

		if(recon_window){
			kit.run(*recon_window);
		}

		delete recon_window;
	}


	/*
	 * WRITE UNIT-SPECIFICATION INFORMATION TO COMMAND-LINE
	 */
	if(argc == 2){
		std::stringstream argss;
		std::string arg;
		argss << argv[1];
		argss >> arg;
		if(arg == "help"){
			UnitConvert<float> uc;
			std::string helpstr;
			helpstr = uc.PrintUnits();
			std::cout << std::endl;
			std::cout << helpstr << std::endl;
		} else {
			std::cout << std::endl;
			std::cout << "ERROR: Unexpected syntax" << std::endl;
			std::cout << std::endl;
			std::cout << "Only 'help' is recognized as a valid option" << std::endl;
			std::cout << "when a single parameter is specified" << std::endl;
			std::cout << std::endl;
		}
	}

	/*
	 * PERFORM UNIT CONVERSION SPECIFIED VIA THE COMMAND-LINE ARGUMENTS
	 * EXPECTED SYNTAX: ./program value units_in units_out
	 *
	 * NUMERICAL RESULT IS RETURNED
	 */
	if(argc == 4){
		typedef long double Tconvert;
		std::stringstream argss;
		std::string unitsin;
		std::string unitsout;
		Tconvert valin;
		Tconvert valout = 0.0e0;
		UnitConvert<Tconvert> uc;

		argss << argv[1];
		argss >> valin; argss.str(""); argss.clear();
		argss << argv[2];
		argss >> unitsin; argss.str(""); argss.clear();
		argss << argv[3];
		argss >> unitsout; argss.str(""); argss.clear();

		valout = uc.ConvertUnits(valin,unitsin,unitsout);

		std::cout << valout << std::endl;
		std::cout << std::endl;
	}


	/*
	 * INFORM THE USER OF CORRECT SYNTAX OPTIONS IF TOO MANY COMMAND-LINE
	 * ARGUMENTS ARE PROVIDED
	 */
	if(argc > 4){
		std::cout << std::endl;
		std::cout << "ERROR: Unexpected syntax" << std::endl;
		std::cout << std::endl;
		std::cout << "Expected syntax options:" << std::endl;
		std::cout << "  1. No arguments provided (run GUI)" << std::endl;
		std::cout << "  2. Unit help printed to CLI by specifying 'help'" << std::endl;
		std::cout << "  3. 3 arguments provided (no GUI)" << std::endl;
		std::cout << "     ex: " << argv[0] << " value units_in units_out" << std::endl;
		std::cout << "     'value' - value to be converted" << std::endl;
		std::cout << "     'units_in' - units of value to be converted" << std::endl;
		std::cout << "     'units_out' - units of output value" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	return 0;
}


