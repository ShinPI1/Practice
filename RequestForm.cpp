char* char_gridCountry, * char_country; 
    char * char_gridDate, * char_date;
    int int_gridPrice, int_price;

    String^ GridName;
    String^ GridCountry;
    String^ GridDate;
row_is_true = true;
        GridName = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[1]->Value);
        GridCountry = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[2]->Value);
        GridDate = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[3]->Value);
        GridNumber1 = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[4]->Value);
        GridNumber2 = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[5]->Value);
        GridNumber3 = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[6]->Value);
        GridNumber4 = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[7]->Value);
        GridNumber5 = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[8]->Value);
        GridPrice = Convert::ToString(dataGridViewRequest->Rows[row]->Cells[9]->Value);
        Convert_String_to_string(GridName, gridName);
