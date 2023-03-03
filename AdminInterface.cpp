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
