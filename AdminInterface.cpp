void PharmacyDB::AdminInterface::Header()
{
    DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
    c1->Name = "Id";
    c1->HeaderText = "id";
    c1->Width = 150;
    dataGridViewAdmin->Columns->Add(c1);

    DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
    c2->Name = "Name";
    c2->HeaderText = "Название";
    c2->Width = 450;
    dataGridViewAdmin->Columns->Add(c2);

    DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
    c3->Name = "Country";
    c3->HeaderText = "Страна-производитель";
    c3->Width = 150;
    dataGridViewAdmin->Columns->Add(c3);

  System::Void PharmacyDB::AdminInterface::buttonEditLine_Click(System::Object^ sender, System::EventArgs^ e)
{
    std::string edit_fileName = "EditRecord.txt";


    String^ Id = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[0]->Value);
    String^ Name = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[1]->Value);
    String^ Country = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[2]->Value);
    String^ Date = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[3]->Value);
    String^ Pharmacy_number1 = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[4]->Value);
    String^ Pharmacy_number2 = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[5]->Value);
    String^ Pharmacy_number3 = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[6]->Value);
    String^ Pharmacy_number4 = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[7]->Value);
    String^ Pharmacy_number5 = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[8]->Value);
      
 std::string name;
    Convert_String_to_string(Name, name);
    std::string country;
    Convert_String_to_string(Country, country);
    std::string date;
    Convert_String_to_string(Date, date);
    std::string pharmacy_number[MAX_PHARMACIES];
    Convert_String_to_string(Pharmacy_number1, pharmacy_number[0]);
    Convert_String_to_string(Pharmacy_number2, pharmacy_number[1]);
    Convert_String_to_string(Pharmacy_number3, pharmacy_number[2]);
    Convert_String_to_string(Pharmacy_number4, pharmacy_number[3]);
    Convert_String_to_string(Pharmacy_number5, pharmacy_number[4]);
    std::string price;
    Convert_String_to_string(Price, price);

System::Void PharmacyDB::AdminInterface::buttonDeleteLine_Click(System::Object^ sender, System::EventArgs^ e)
{
    MessageBoxButtons buttons = MessageBoxButtons::YesNo;
    String^ Current_id = Convert::ToString(dataGridViewAdmin->CurrentRow->Cells[0]->Value);
    std::string current_id;
    Convert_String_to_string(Current_id, current_id);
    int int_current_id = std::stoi(current_id);
    if (MessageBox::Show("Вы точно хотите удалить запись с id = " + int_current_id +" ?", "Уведомление", buttons) == System::Windows::Forms::DialogResult::Yes) {
        String^ Current_id = dataGridViewAdmin->CurrentRow->Cells[0]->Value->ToString();
        std::string current_id;
        Convert_String_to_string(Current_id, current_id);
        int cur_id = atoi(current_id.c_str());
        dataGridViewAdmin->Rows->Remove(dataGridViewAdmin->CurrentRow);
        dataGridViewAdmin->Refresh();
        int count_rows = dataGridViewAdmin->Rows->Count;
        for (cur_id; cur_id < count_rows; cur_id++) {
            if (cur_id == count_rows - 1) {
                dataGridViewAdmin->Rows[cur_id]->Cells[0]->Value = "";
            }
            else{
                String^ New_id = dataGridViewAdmin->Rows[cur_id]->Cells[0]->Value->ToString();
                std::string new_id;
                Convert_String_to_string(New_id, new_id);
                int int_new_id = atoi(new_id.c_str());
                dataGridViewAdmin->Rows[cur_id]->Cells[0]->Value = --int_new_id;
            }
           
        }
        Save_data_grid_in_file(fileName);
    }
    return System::Void();
}
