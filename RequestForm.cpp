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
        char_gridCountry = Convert_String_to_char(GridCountry);
        char_country = Convert_String_to_char(Country);
        Convert_String_to_string(GridDate, gridDate);
        char_gridDate = Convert_String_to_char(GridDate);
        char_date = Convert_String_to_char(Date);
        Convert_String_to_string(GridNumber1, gridNumber1);
        Convert_String_to_string(GridNumber2, gridNumber2);
        Convert_String_to_string(GridNumber3, gridNumber3);
        Convert_String_to_string(GridNumber4, gridNumber4);
        Convert_String_to_string(GridNumber5, gridNumber5);
        Convert_String_to_string(GridPrice, gridPrice);
       
        if (date != "") {
            if (strcmp(char_gridDate, char_date) <= 0) row_is_true = false;
        }
        if (number != "") {
            if (number != gridNumber1 && number != gridNumber2 && number != gridNumber3 && number != gridNumber4 && number != gridNumber5) row_is_true = false;
        }
