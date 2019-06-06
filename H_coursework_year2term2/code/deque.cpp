#include "deque.h"

Deque::Deque():head(nullptr), tail(nullptr), size_(0) {}

unsigned int Deque::size() const
{
    return size_;
}

void Deque::pushFront(CommercialOrg *data)
{
    Node *temp = new Node;//создаем узел temp который бедет хранить наши данные переданные в параметр фции
    temp->data = data;
    temp->next = head;//следующий за узлом temp элемент - голова
    temp->prev = nullptr;//предыдущий перед узлом temp элемент - пустой
    temp->seen = 0;

    if (head)//если голова существует, то
        head->prev = temp;//предыдущий перед головой элемент будет temp

    head = temp;//голова = temp

    if (!tail)//если хвост не существует, то в деке только один элемент который мы как раз добавили
        tail = head;//хвост равен голове (а в голове на данный момент храниться temp)

    size_++;//увеличиваем длину списка на 1 т к добавили  1 элемент
}

CommercialOrg *Deque::popFront()//пользователь должен будет вручную освободить данные что храняться по возвращенному функцией указателю
{
    CommercialOrg *data(nullptr);//создаем дату и заполняем ее нулем

    if (head)//если голова есть, значит можем ее отрезать
    {
        if (Bank *successfulCast = dynamic_cast<Bank *>(head->data))//если в голове находиться элемент типа данных банк
        {
            data = new Bank;//выделяем под него память
            *(Bank *)data = *(Bank *)(head->data);//присваиваем в область памяти что находиться по указателю data
                                  // элемент хранящийся в head. таким образом мы также производим копирование данных
        }
        else//аналогичные действия совершаем если объект оказался типа InsuranceCompany
        {
            data = new InsuranceComp;
            *(InsuranceComp *)data = *(InsuranceComp *)(head->data);
        }

        Node *temp = head;//создаем временный узел temp и присваиваем в него голову
        head = head->next;//перемещаем голову на 1 позицию
        temp->seen = 0;

        if (head)//если новая голова (мы ее перместили) существует, то
            head->prev = nullptr;//"говорим" ей о том что элемент перед ней (то есть старая голова) будет удален

        delete temp;//удаляем temp то есть старую голову
        size_--;//уменьшаем сайз
    }

    return data;//возвращаем данные которые хранились в голове которую мы отрезали
}

void Deque::sortByCapital()
{
    if (!size_)
        return;

	Node *i;
	Node *j;
	Node *minIdx;
	int size = size_;

	for (i = head; i != nullptr; i = i->next)
	{
		minIdx = i;
		for (j = i->next; j != nullptr; j = j->next)
		{
			if (j->data->getStatMoneyCapital() < minIdx->data->getStatMoneyCapital())
				minIdx = j;
		}

		CommercialOrg *temp = minIdx->data;
		minIdx->data = i->data;
		i->data = temp;
	}
}

CommercialOrg *Deque::popBack()
{
    CommercialOrg *data(nullptr);//создаем переменную для данных из хвоста

    if (tail)//если есть хвост значит его можно отрезать
    {
        if (Bank *successfulCast = dynamic_cast<Bank *>(head->data))//если в голове находиться элемент типа данных банк
        {
            data = new Bank;//выделяем под него память
            *data = *(head->data);//присваиваем в область памяти что находиться по указателю data
                                  // элемент хранящийся в head. таким образом мы также производим копирование данных
        }
        else//аналогичные действия совершаем если объект оказался типа InsuranceCompany
        {
            data = new InsuranceComp;
            *data = *(head->data);
        }

        Node *temp = tail;//создаем временный узел temp куда присваиваем хвост
        tail = tail->prev;//передвигаем хвост на шаг назад

        if (tail)//если новый хвост существует
            tail->next = nullptr;//показываем что за ним не будет элементов

        delete temp;//удаляем старый хвост
        size_--;//уменьшаем сайз

    }

    return data;//возвращаем данные
}

void Deque::clear()
{
    Node *temp;//создаем временный узел temp
    while (head)//пока голова существует
    {
        temp = head;//присваиваем в temp head
        head = head->next;//перемещаем голову
        delete temp;//удаляем temp - старую голову
    }
    head = nullptr;//
    tail = nullptr;//явно указываем что дек пуст
    size_ = 0;    //
}

ostream &operator<<(ostream &output, const Deque &d)
{
    Node *tmp = d.head;

    output << (string)"\n--------------------------------------------------------\n";
    while (tmp)
    {
        output << tmp->data;//tmp.outputObj
        tmp = tmp->next;
    }
    output << (string)"\n--------------------------------------------------------\n";

	return output;
}

Deque::~Deque()
{
    clear();//вызываем фкцию очистки
}

/*
void Deque::sortByCapital_()
{
	Deque cpiedD;

	unsigned int tmpData;// = d.head->data->getStatMoneyCapital();
	//Node *tmpNode = new Node;

	for(unsigned int i = 0; i < size_; i++)
	{
		bool find = 0;
		CommercialOrg *tmpData = new Bank;

		Node *tmp = head;
		while (tmp)
		{
			if (!tmp->seen)
			{
				tmpData->setStatMoneyCapital(tmp->data->getStatMoneyCapital());
				tmp = head;
				break;
			}
			tmp = tmp->next;
		}

		while (tmp)
		{
			if (!tmp->seen && tmp->data->getStatMoneyCapital() < tmpData->getStatMoneyCapital())//&& cpiedD.has_no(tmp))
			{
				find = 1;
				delete tmpData;
				tmpData = tmp->data;
				tmp->seen = 1;
			}
			tmp = tmp->next;
		}
		if (find)
			cpiedD.pushFront(tmpData);//!!!
	}
	///delete tmpNode;
	//cpiedD.size_ = d.size_;

}
*/