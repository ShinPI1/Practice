int show_meds(int _countData) { // ФУНКЦИЯ ВЫВОДА ВСЕХ ЛЕКАРСТВ
	char fileName[] = "medicines.txt"; //основной файл
////////////////////////////////////////////////////////////////////////////////////////////////////
	/*med - структура для добавления записи, редактирования записи new_med - для записи данных при редактировании*/
	std::string name;
	struct {
		int id; //ключ
		std::string name, //название
		country, //страна-производитель
		date; //дата производства
		int pharmacy_number[MAX_PHARMACIES]; //номера аптек
		int price; //максимальная цена
	} med, new_med;
	if (_countData == 0)
	{
		MessageBox::Show("Записей в файле нет", "Предупреждение");
	}

  //MessageBox::Show(Convert::ToString(countData_), "1");
file = fopen(fileName_, "a");//Создание файла на случай, если он не создан
fclose(file);
file = fopen(fileName_, "r+");//чтение кол-ва записей или запись нуля при их отсутствии
	if (file == NULL)
		MessageBox::Show("Файл не открылся", "Ошибка");// Файл не открылся 
	rewind(file);
	fscanf(file, "%d", &countData_);
	if (countData_ == NULL) fprintf(file, "%d\n", 0); //записываем 0 (кол-во записей) в начало
	else {
		rewind(file);
		fscanf(file, "%d", &countData_);
	}
fclose(file);
return countData_;
}
int show_meds(int _countData) { // ФУНКЦИЯ ВЫВОДА ВСЕХ ЛЕКАРСТВ
	char fileName[] = "medicines.txt"; //основной файл
////////////////////////////////////////////////////////////////////////////////////////////////////
	/*med - структура для добавления записи, редактирования записи new_med - для записи данных при редактировании*/
	std::string name;

