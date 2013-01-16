/**
 * @file GUIUnitConvert.h
 * @author 	Robert Grandin
 * @date 23 June 2011
 *
 * @section Class Description & Notes
 *
 * This class defines the attributes and callback funcions of the Graphical
 * User Interface (GUI) used in the unit conversion executables.
 *
 * For information regarding using this class as a derived class, refer to the
 * GTKmm documentation:
 * <a href="http://library.gnome.org/devel/gtkmm-tutorial/2.21/sec-builder-using-derived-widgets.html.en">
 * GNOME Documentation Library</a>.
 *
 * All functions contained within this class are intended for use with the GNU
 * C++ compiler (g++).  Use with other compilers may produce unexpected results
 * and such use is at the users' own risk.
 *
 *
 *
 * @section Prerequisites
 *
 * This class requires the GTKmm development libraries.
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

#ifndef GUIUnitConvert_
#define GUIUnitConvert_

#include <iostream>
using namespace std;
#include <iomanip>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <sigc++/retype_return.h>
#include <glib.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <cmath>
#include <memory>
#include <time.h>
#include <gtkmm.h>
#include <omp.h>
#include <UnitConvert.h>

/**
 * @brief This class defines the GUI used with the Laminography Reconstruction
 * 			executables.
 */

class GUIUnitConvert : public Gtk::Window {

public:
	/**
	 * @brief Constructor for the GUI class.
	 * @pre None.
	 * @post GUIUnitConvert object exists and GUI is launched.
	 * @return None.
	 */
	GUIUnitConvert();


	/**
	 * @brief Constructor for use as a derived type.  This is the constructor
	 * 			called in my implementation of this class as it is used as
	 * 			a widget derived from a main window.
	 * @pre None.
	 * @param cobject Base object type.
	 * @param refGlade Gtk::Builder instance.
	 * @post GUIUnitConvert object exists and GUI is launched.
	 * @return None.
	 */
	GUIUnitConvert(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);

	/**
	 * @brief Deconstructor for the GUI class.
	 * @pre None.
	 * @post GUIUnitConvert object destroyed.
	 * @return None.
	 */
	~GUIUnitConvert();



protected:


	/**
	 * @brief Template for extracting a number (type float, double, or int) from
	 * 			an input text box.
	 * @pre GUIUnitConvert object extists.
	 * @param t Reference to the variable to contain the numeric data extracted
	 * 			from the text box (must be of type 'T').
	 * @param s Reference to string retreived from the text box.
	 * @param f Indicator for type of number to be extracted.  Use 'std@::dec' for
	 * 			decimal numbers.
	 * @post String data 's' stored in 't' as the appropriate numeric type.
	 * @return Boolean value indicating success or failure
	 */
	template <class T>
	bool from_string(T& t, const std::string& s,
			std::ios_base& (*f)(std::ios_base&));


	/**
	 * @brief Show the About dialog box.
	 * @pre GUIUnitConvert object exists.
	 * @post Dialog box shown.
	 * @return None.
	 */
	void showabout();


	/**
	 * @brief Close the About dialog box.
	 * @pre GUIUnitConvert object exists.
	 * @param response Response from GUI.  Not used in this callback.
	 * @post Dialog box shown.
	 * @return None.
	 */
	void on_dlg_about_close(int response);


	/**
	 * @brief Show the Help->Reference dialog box.
	 * @pre GUIUnitConvert object exists.
	 * @post Dialog box shown.
	 * @return None.
	 */
	void showreference();


	/**
	 * @brief Close the Help->Reference dialog box.
	 * @pre GUIUnitConvert object exists.
	 * @param response Response from GUI.  Not used in this callback.
	 * @post Dialog box shown.
	 * @return None.
	 */
	void on_btn_dlg_msg_clicked(int response);


	/**
	 * @brief Add the user-specified input units to the input unit string.
	 * @pre GUIUnitConvert object exists.
	 * @post Input unit string updated.
	 * @return None.
	 */
	virtual void on_btn_menu_input_add_clicked();


	/**
	 * @brief Clear the current input units.
	 * @pre GUIUnitConvert object exists.
	 * @post Input units cleared and output value set to 0.0.
	 * @return None.
	 */
	virtual void on_btn_menu_input_clear_clicked();


	/**
	 * @brief Add the user-specified input units to the output unit string.
	 * @pre GUIUnitConvert object exists.
	 * @post Output unit string updated.
	 * @return None.
	 */
	virtual void on_btn_menu_output_add_clicked();


	/**
	 * @brief Clear the current output units.
	 * @pre GUIUnitConvert object exists.
	 * @post Output units cleared and output value set to 0.0.
	 * @return None.
	 */
	virtual void on_btn_menu_output_clear_clicked();


	/**
	 * @brief Perform the desired conversion.
	 * @pre GUIUnitConvert object exists.
	 * @post Conversion performed and result placed in output label.
	 * @return None.
	 */
	virtual void on_btn_menu_convert_clicked();


	/**
	 * @brief Perform the desired conversion.
	 * @pre GUIUnitConvert object exists.
	 * @post Conversion performed and result placed in output label.
	 * @return None.
	 */
	virtual void on_btn_manual_convert_clicked();


	/** @brief XML interface file for GUI */
	Glib::RefPtr<Gtk::Builder> xml_interface;


	// ===================================================================
	// ================ WINDOWS

	/** @brief Main window */
	Gtk::Window *p_window;



	// ===================================================================
	// ================ DIALOG BOXES
	/** @brief About dialog box */
	Gtk::Dialog *dlg_about;

	/** @brief Message dialog box */
	Gtk::Dialog *dlg_msg;




	// ===================================================================
	// ================ BUTTONS
	/** @brief Button to add the unit specified by the input combo boxes to the
	 * unit string */
	Gtk::Button *btn_menu_input_add;

	/** @brief Button to add the unit specified by the output combo boxes to the
	 * unit string */
	Gtk::Button *btn_menu_output_add;

	/** @brief Button to clear all widgets and "reset" the entire GUI */
	Gtk::Button *btn_menu_clear;

	/** @brief Button to perform the specified conversion using the menu-driven
	 * unit strings */
	Gtk::Button *btn_menu_convert;

	/** @brief Button to clear the input unit string and reset the input widgets */
	Gtk::Button *btn_menu_input_clear;

	/** @brief Button to clear the output unit string and reset the input widgets */
	Gtk::Button *btn_menu_output_clear;

	/** @brief Button to clear all widgets and "reset" the entire GUI */
	Gtk::Button *btn_manual_clear;

	/** @brief Button to perform the specified conversion using the manually-entered
	 * unit strings */
	Gtk::Button *btn_manual_convert;

	/** @brief Button to close the message dialog box */
	Gtk::Button *btn_dlg_msg;



	// ===================================================================
	// ================ TEXT-ENTRY BOXES
	/** @brief Value to be converted using the menu-driven unit selection */
	Gtk::Entry *txt_menu_input;

	/** @brief Entry box for the power associated with the input unit being entered
	 * using the combo boxes */
	Gtk::Entry *txt_menu_input_power;

	/** @brief Entry box for the power associated with the input unit being entered
	 * using the combo boxes */
	Gtk::Entry *txt_menu_output_power;

	/** @brief Entry box for the manually-entered input unit string */
	Gtk::Entry *txt_manual_input_units;

	/** @brief Entry box for the manually-entered output unit string */
	Gtk::Entry *txt_manual_output_units;

	/** @brief Value to be converted using the manually-entered input strings */
	Gtk::Entry *txt_manual_input;




	// ===================================================================
	// ================ FILECHOOSERS





	// ===================================================================
	// ================ RADIO BUTTONS





	// ===================================================================
	// ================ CHECKBOXES





	// ===================================================================
	// ================ LABELS
	/** @brief Output result on the menu-driven conversion */
	Gtk::Label *lbl_menu_output;

	/** @brief Input unit string to be used in the conversion, generated using
	 * the combo-boxes */
	Gtk::Label *lbl_menu_input_units;

	/** @brief Output unit string to be used in the conversion, generated using
	 * the combo-boxes */
	Gtk::Label *lbl_menu_output_units;

	/** @brief Output result on the manually-entered conversion */
	Gtk::Label *lbl_manual_output;

	/** @brief Title to be displayed in the message dialog box */
	Gtk::Label *lbl_dlg_msg_title;

	/** @brief Body of message to be displayed in the message dialog box */
	Gtk::Label *lbl_dlg_msg_body;




	// ===================================================================
	// ================ COMBOBOXES
	/** @brief SI prefix to use with the input unit */
	Gtk::ComboBox *cbo_menu_input_si;

	/** @brief Input unit */
	Gtk::ComboBox *cbo_menu_input_unit;

	/** @brief SI prefix to use with the output unit */
	Gtk::ComboBox *cbo_menu_output_si;

	/** @brief Output unit */
	Gtk::ComboBox *cbo_menu_output_unit;



	// ===================================================================
	// ================ MENU ITEMS

	/** @brief File->Quit menu item */
	Gtk::MenuItem *mnu_quit;

	/** @brief Help->About menu item */
	Gtk::MenuItem *mnu_help_about;

	/** @brief Help->Help menu item */
	Gtk::MenuItem *mnu_help_reference;




	// ===================================================================
	// ================ PROGRESS BAR



	// ===================================================================
	// ================ TREE MODEL
	/** @brief Tree-model for SI units */
	Glib::RefPtr<Gtk::TreeStore> TreeModelSI;

	/** @brief Tree-model for units */
	Glib::RefPtr<Gtk::TreeStore> TreeModelUnit;



	// ===================================================================
	// ================ TREE MODEL COLUMNS
	/**
	 * @brief Define the model for the columns to be displayed in each combo-box.
	 */
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
	{
	public:

		ModelColumns()
		{ add(m_col_name); }

		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
	};

	/** @brief Column model for SI prefix combo-boxes */
	ModelColumns ModelColumnsSI;

	/** @brief Column model for unit combo-boxes */
	ModelColumns ModelColumnsUnit;




private:
	// ===================================================================
	// ================ VARIABLES

	// ===================================================================
	// ================ FUNCTIONS
	/**
	 * @brief Reset the GUI to its original state.
	 * @pre GUIUnitConvert object exists.
	 * @post GUI reset to original state.
	 * @return None.
	 */
	void Reset();



};

// ==================================================================
// ================
// ================    PRIVATE FUNCTIONS
// ================


void GUIUnitConvert::Reset()
{
	lbl_menu_input_units->set_text("[-]");
	lbl_menu_output_units->set_text("[-]");
	lbl_menu_output->set_text("0.0");
	txt_menu_input->set_text("1.0");
	txt_menu_input_power->set_text("1");
	txt_menu_output_power->set_text("1");
	lbl_manual_output->set_text("0.0");
	txt_manual_input->set_text("1.0");
	txt_manual_input_units->set_text("");
	txt_manual_output_units->set_text("");
	cbo_menu_input_si->set_active(0);
	cbo_menu_input_unit->set_active(0);
	cbo_menu_output_si->set_active(0);
	cbo_menu_output_unit->set_active(0);
}




// ==================================================================
// ================
// ================    PUBLIC FUNCTIONS
// ================

// CONSTRUCTOR
GUIUnitConvert::GUIUnitConvert()
{
	// NOTHING.  DERIVED CONSTRUCTOR ALWAYS USED.
}


// DESTRUCTOR
GUIUnitConvert::~GUIUnitConvert()
{
	// NOTHING.
}

// DIALOG BOX SHOW/HIDE FUNCTIONS
void GUIUnitConvert::showabout()
{
	if(dlg_about){
		dlg_about->run();
	}
}


void GUIUnitConvert::on_dlg_about_close(int response)
{
	dlg_about->hide();
}


// WINDOW CREATION & WIDGET SIGNAL CONNECTION TO FUNCTIONS
GUIUnitConvert::GUIUnitConvert(BaseObjectType* cobject,
		const Glib::RefPtr<Gtk::Builder>& refGlade) : Gtk::Window(cobject),
													  xml_interface(refGlade)
{
	/*
	 * CONSTRUCT THE GRAPHICAL INTERFACE.  DEFAULT VALUES ARE SET AND WIDGET
	 * SIGNALS ARE CONNECTED TO CALLBACK FUNCTIONS.
	 */

	// GET WIDGETS FROM GLADE INTERFACE & CONNECT TO POINTERS
	// ---- DIALOG BOXES
	xml_interface->get_widget("dlg_about",dlg_about);
	xml_interface->get_widget("dlg_msg",dlg_msg);


	// ---- BUTTONS
	xml_interface->get_widget("btn_menu_clear",btn_menu_clear);
	xml_interface->get_widget("btn_menu_input_add",btn_menu_input_add);
	xml_interface->get_widget("btn_menu_output_add",btn_menu_output_add);
	xml_interface->get_widget("btn_menu_convert",btn_menu_convert);
	xml_interface->get_widget("btn_menu_input_clear",btn_menu_input_clear);
	xml_interface->get_widget("btn_menu_output_clear",btn_menu_output_clear);
	xml_interface->get_widget("btn_manual_clear",btn_manual_clear);
	xml_interface->get_widget("btn_manual_convert",btn_manual_convert);
	xml_interface->get_widget("btn_dlg_msg",btn_dlg_msg);


	// ---- MENU ITEMS
	xml_interface->get_widget("mnu_help_about",mnu_help_about);
	xml_interface->get_widget("mnu_quit",mnu_quit);
	xml_interface->get_widget("mnu_help_reference",mnu_help_reference);


	// ---- COMBO BOXES
	xml_interface->get_widget("cbo_menu_input_si",cbo_menu_input_si);
	xml_interface->get_widget("cbo_menu_input_unit",cbo_menu_input_unit);
	xml_interface->get_widget("cbo_menu_output_si",cbo_menu_output_si);
	xml_interface->get_widget("cbo_menu_output_unit",cbo_menu_output_unit);


	// ---- CHECK BOXES


	// ---- RADIO BUTTONS


	// ---- TEXT BOXES
	xml_interface->get_widget("txt_menu_input",txt_menu_input);
	xml_interface->get_widget("txt_menu_input_power",txt_menu_input_power);
	xml_interface->get_widget("txt_menu_output_power",txt_menu_output_power);
	xml_interface->get_widget("txt_manual_input",txt_manual_input);
	xml_interface->get_widget("txt_manual_input_units",txt_manual_input_units);
	xml_interface->get_widget("txt_manual_output_units",txt_manual_output_units);


	// ---- LABELS
	xml_interface->get_widget("lbl_menu_input_units",lbl_menu_input_units);
	xml_interface->get_widget("lbl_menu_output",lbl_menu_output);
	xml_interface->get_widget("lbl_menu_output_units",lbl_menu_output_units);
	xml_interface->get_widget("lbl_manual_output",lbl_manual_output);
	xml_interface->get_widget("lbl_dlg_msg_title",lbl_dlg_msg_title);
	xml_interface->get_widget("lbl_dlg_msg_body",lbl_dlg_msg_body);


	// ---- FILE CHOOSER BUTTONS


	// ---- PROGRESS BAR



	// CALLBACK FUNCTIONS
	// ---- DIALOG BOXES
	dlg_about->signal_response().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_dlg_about_close));
	dlg_msg->signal_response().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_btn_dlg_msg_clicked));


	// ---- BUTTONS
	btn_menu_clear->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::Reset));
	btn_menu_input_add->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_btn_menu_input_add_clicked));
	btn_menu_output_add->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_btn_menu_output_add_clicked));
	btn_menu_convert->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_btn_menu_convert_clicked));
	btn_menu_input_clear->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_btn_menu_input_clear_clicked));
	btn_menu_output_clear->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_btn_menu_output_clear_clicked));
	btn_manual_clear->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::Reset));
	btn_manual_convert->signal_clicked().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::on_btn_manual_convert_clicked));



	// ---- MENU ITEMS
	mnu_quit->signal_activate().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::hide));
	mnu_help_about->signal_activate().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::showabout));
	mnu_help_reference->signal_activate().connect
		(sigc::mem_fun(*this, &GUIUnitConvert::showreference));

	// ---- CHECK BOXES


	// ---- FILECHOOSERS


	// ---- TEXT BOXES


	// ---- COMBO BOXES



	/*
	 * POPULATE COMBO BOXES
	 */
	TreeModelSI = Gtk::TreeStore::create(ModelColumnsSI);
	TreeModelUnit = Gtk::TreeStore::create(ModelColumnsUnit);
	cbo_menu_input_si->set_model(TreeModelSI);
	cbo_menu_output_si->set_model(TreeModelSI);
	cbo_menu_input_unit->set_model(TreeModelUnit);
	cbo_menu_output_unit->set_model(TreeModelUnit);

	Gtk::TreeModel::Row rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "y (10^-24)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "z (10^-21)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "a (10^-18)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "f (10^-15)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "p (10^-12)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "n (10^-09)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "u (10^-06)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "m (10^-03)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "c (10^-02)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "d (10^-01)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "- (10^00)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "da (10^01)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "h (10^02)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "k (10^03)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "M (10^06)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "G (10^09)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "T (10^12)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "P (10^15)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "E (10^18)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "Z (10^21)";
	rowSI = *(TreeModelSI->append());
	rowSI[ModelColumnsSI.m_col_name] = "Y (10^24)";



	Gtk::TreeModel::Row rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Acceleration";
	Gtk::TreeModel::Row childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "gee (gravitational acceleration at Earth's surface)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Angle";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "deg (degrees)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "grad (gradian)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "radian (radians)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Area";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "acre (acres)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ha (hectares)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Energy/Moment/Torque/Work";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "BTU (British Thermal Units)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "cal (small (gram) calories)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "Cal (large (dietary) calories)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "erg (ergs)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "eV (electron volts)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ft_lbf (foot-pounds-force)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "J (Joules)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "N_m (Newton-meters)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Force";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "bpound (Biblical pounds)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "cwt (US hundredweight)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "dyn (dynes)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "gerah (Biblical gerahs)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "lbf (pounds-force)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "mina (Biblical minas)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "N (Newtons)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "oz (US ounces, non-fluid)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "shek (Biblical shekels)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "tal (Biblical talents)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Length";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "AU (astronomical units)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "cb (cables)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "chain (chains)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "cubit (Biblical cubits, 18-inch definition)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ft (feet)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ftm (fathoms)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "fur (furlongs)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "hand (hands)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "in (inches)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "lea (leagues)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "li (links)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ly (light years)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "m (meters)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "mile (miles)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "nmi (nautical miles)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "p (points)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "P (picas)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ps (parsecs)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "rod (rods)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "sdj (Sabbath day's journeys)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "span (Biblical spans)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Mass";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "dr (drams)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "dwt (pennyweight)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "g (grams)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "gr (grains)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "lbm (pounds-mass)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "slug (slugs)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Power";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "hp (horsepower, 1 hp = ~746 W)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "W (Watts)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Pressure";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "at (technical atmospheres)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "atm (atmospheres)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "bar (100 kPa)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ksi (1000 psi)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "Pa (Pascals)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "psi (pounds-force per square inch)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "torr (Torrs)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Quantity";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "mol (6.02 x10^23 particles)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Radioactive Decay";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "Bq (becquerels)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "Ci (Curies)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Radiation Dose";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "Gy (Grays)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "rad (radiation dose)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "rem (rad-equivalent-man, assuming Q = 1)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "Sv (Sieverts)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Radiation Quantity";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "R (Roentgens)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Temperature";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "C (degrees Celcius)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "F (degrees Fahrenheight)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "K (Kelvins)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Time";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "day (days)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "hr (hours)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "min (minutes)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "sec (seconds)";

	rowUnit = *(TreeModelUnit->append());
	rowUnit[ModelColumnsUnit.m_col_name] = "Volume";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "bath (Biblical baths)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "bbl (oil barrels)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "bu (bushels)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "cup (US cups)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "dbbl (dry barrels)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "dpt (dry pint)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "dqt (dry quart)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "ephah (Biblical ephahs)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "fl_dr (US fluid drams)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "fl_oz (US fluid ounces)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "gal (US gallons)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "gi (gills)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "hin (Biblical hins)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "hghd (hogsheads)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "homer (Biblical homers)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "imp_gal (imperial gallons)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "jig (jiggers)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "L (liters)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "lbbl (liquid barrels)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "minim (minims)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "omer (Biblical omers)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "pk (pecks)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "lpt (US pints)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "lqt (US quarts)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "tsp (teaspoons)";
	childrowUnit = *(TreeModelUnit->append(rowUnit.children()));
	childrowUnit[ModelColumnsUnit.m_col_name] = "Tbsp (tablespoons)";


}

// TEMPLATE FOR CONVERTING STRING DATA RETRIEVED FROM ENTRY BOXES TO NUMERIC
// TYPES (int OR float).
template <class T>
bool GUIUnitConvert::from_string(T& t,
		const std::string& s,
                 std::ios_base& (*f)(std::ios_base&))
{
	std::istringstream iss(s);
	return !(iss >> f >> t).fail();
}


void GUIUnitConvert::on_btn_menu_input_add_clicked()
{
	/*
	 * GET VALUES SPECIFIED BY USER FOR SI PREFIX, UNIT, AND POWER
	 */
	std::string si;
	std::string unit;
	std::string power;
	std::stringstream sstmp;

	Gtk::TreeModel::iterator iter = cbo_menu_input_si->get_active();
	if(iter){
		Gtk::TreeModel::Row row = *iter;
		if(row){
			Glib::ustring name = row[ModelColumnsSI.m_col_name];
			sstmp << name; sstmp >> si; sstmp.str(""); sstmp.clear();
		}
	}

	/* TO SET A COMBO BOX TO MATCH A DIFFERENT ONE:
	cbo_menu_output_si->set_active(iter);
	cbo_menu_input_si->set_active(iter);
	*/

	iter = cbo_menu_input_unit->get_active();
	if(iter){
		Gtk::TreeModel::Row row = *iter;
		if(row){
			Glib::ustring name = row[ModelColumnsUnit.m_col_name];
			sstmp << name; sstmp >> unit; sstmp.str(""); sstmp.clear();
		}
	}

	power = txt_menu_input_power->get_text();


	/*
	 * CHECK CURRENT "SAVED" UNITS
	 */
	std::string currentinputunits;
	currentinputunits = lbl_menu_input_units->get_text();


	/*
	 * ADD VALUES FROM BOXES TO CURRENT UNIT LABEL AND UPDATE LABEL ON THE GUI
	 */
	if(currentinputunits == "[-]"){
		currentinputunits = "";
	} else {
		currentinputunits += "|";
	}
	currentinputunits += si + ":" + unit + ":" + power;
	lbl_menu_input_units->set_text(currentinputunits);
}


void GUIUnitConvert::on_btn_menu_input_clear_clicked()
{
	lbl_menu_input_units->set_text("[-]");
	lbl_menu_output->set_text("0.0");
	txt_menu_input->set_text("1.0");
	txt_menu_input_power->set_text("1");
	cbo_menu_input_si->set_active(0);
	cbo_menu_input_unit->set_active(0);
}


void GUIUnitConvert::on_btn_menu_output_clear_clicked()
{
	lbl_menu_output_units->set_text("[-]");
	lbl_menu_output->set_text("0.0");
	txt_menu_output_power->set_text("1");
	cbo_menu_output_si->set_active(0);
	cbo_menu_output_unit->set_active(0);
}


void GUIUnitConvert::on_btn_menu_output_add_clicked()
{
	/*
	 * GET VALUES SPECIFIED BY USER FOR SI PREFIX, UNIT, AND POWER
	 */
	std::string si;
	std::string unit;
	std::string power;
	std::stringstream sstmp;

	Gtk::TreeModel::iterator iter = cbo_menu_output_si->get_active();
	if(iter){
		Gtk::TreeModel::Row row = *iter;
		if(row){
			Glib::ustring name = row[ModelColumnsSI.m_col_name];
			sstmp << name; sstmp >> si; sstmp.str(""); sstmp.clear();
		}
	}

	iter = cbo_menu_output_unit->get_active();
	if(iter){
		Gtk::TreeModel::Row row = *iter;
		if(row){
			Glib::ustring name = row[ModelColumnsUnit.m_col_name];
			sstmp << name; sstmp >> unit; sstmp.str(""); sstmp.clear();
		}
	}

	power = txt_menu_output_power->get_text();


	/*
	 * CHECK CURRENT "SAVED" UNITS
	 */
	std::string currentoutputunits;

	currentoutputunits = lbl_menu_output_units->get_text();


	/*
	 * ADD VALUES FROM BOXES TO CURRENT UNIT LABEL AND UPDATE LABEL ON THE GUI
	 */
	if(currentoutputunits == "[-]"){
		currentoutputunits = "";
	} else {
		currentoutputunits += "|";
	}
	currentoutputunits += si + ":" + unit + ":" + power;
	lbl_menu_output_units->set_text(currentoutputunits);
}


void GUIUnitConvert::on_btn_menu_convert_clicked()
{
	UnitConvert<double> uc;

	/*
	 * GET VALUE TO BE CONVERTED
	 */
	std::string sval;
	std::stringstream sstmp;
	double val = 0.0e0;
	double ldtmp = 0.0e0;
	sval = txt_menu_input->get_text();
	if(from_string<double>(ldtmp, std::string(sval), std::dec))
	{
		val = ldtmp;
	}

	/*
	 * CHECK SPECIFIED INPUT AND OUTPUT UNITS
	 */
	std::string currentinputunits;
	std::string currentoutputunits;
	currentinputunits = lbl_menu_input_units->get_text();
	currentoutputunits = lbl_menu_output_units->get_text();
	if(currentinputunits == "[-]"){
		currentinputunits = "x.x.0";
	}
	if(currentoutputunits == "[-]"){
		currentoutputunits = "z.z.0";
	}


	/*
	 * PERFORM CONVERSION
	 */
	double valout = 0.0e0;
	valout = uc.ConvertUnits(val,currentinputunits,currentoutputunits);
	/*
	printf("%g [%s] = %g [%s]\n",val,currentinputunits.c_str(),valout,
			currentoutputunits.c_str());
	*/

	/*
	 * PLACE RESULT INTO GUI
	 */
	sstmp.clear();
	sstmp << valout;
	lbl_menu_output->set_text(sstmp.str());
	sstmp.clear();
}


void GUIUnitConvert::on_btn_manual_convert_clicked()
{
	UnitConvert<double> uc;

	/*
	 * GET VALUE TO BE CONVERTED
	 */
	std::string sval;
	std::stringstream sstmp;
	double val = 0.0e0;
	double ldtmp = 0.0e0;
	sval = txt_manual_input->get_text();
	if(from_string<double>(ldtmp, std::string(sval), std::dec))
	{
		val = ldtmp;
	}

	/*
	 * CHECK SPECIFIED INPUT AND OUTPUT UNITS
	 */
	std::string currentinputunits;
	std::string currentoutputunits;
	currentinputunits = txt_manual_input_units->get_text();
	currentoutputunits = txt_manual_output_units->get_text();


	/*
	 * PERFORM CONVERSION
	 */
	double valout = 0.0e0;
	valout = uc.ConvertUnits(val,currentinputunits,currentoutputunits);
	/*
	printf("%g [%s] = %g [%s]\n",val,currentinputunits.c_str(),valout,
			currentoutputunits.c_str());
	 */

	/*
	 * PLACE RESULT INTO GUI
	 */
	sstmp.clear();
	sstmp << valout;
	lbl_manual_output->set_text(sstmp.str());
	sstmp.clear();
}


void GUIUnitConvert::showreference()
{
	std::string title("Reference");
	std::string msg;

	UnitConvert<float> uc;
	msg = uc.PrintUnits();

	// SET LABELS
	lbl_dlg_msg_title->set_text(title);
	lbl_dlg_msg_body->set_text(msg);

	// RUN DIALOG
	if(dlg_msg){
		dlg_msg->run();
	}
}


void GUIUnitConvert::on_btn_dlg_msg_clicked(int response)
{
	dlg_msg->hide();
}


#endif /* GUIUnitConvert_ */
