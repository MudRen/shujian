// guest.c �����

inherit NPC;

string *first_name = ({ "��","��","��","��","��","֣","��","��","��","��","��","��","��", }); 
string *man_name_words = ({ "��","˳","��","��","��","��","��","ս","��", });
string *woman_name_words = ({ "��","��","��","��","��","��","��","ܷ","��", });
string *xing = ({ "����","Ů��", });

void create()
{
	int age;
	string name,xingbie;
		age = 20 + random(40);
		xingbie = xing[random(sizeof(xing))];
        name = first_name[random(sizeof(first_name))];
        if (xingbie !="����")
		{
		name += woman_name_words[random(sizeof(woman_name_words))]; 
        } else { name += man_name_words[random(sizeof(man_name_words))]; }
 

	set_name(name, ({ "guest" }));
    set("title", "�����");
    set("gender", xingbie);
	set("age", age);
	set_skill("unarmed", random(40));
	set_skill("dodge", random(40));
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 150+age*10);
	set("shen_type", 1);
		 set("chat_chance", 2);

	 set("chat_msg", ({
	 "����͵���������һ����Ϊ�������λ���Ӱ\n",
	 "����ͱ�Ŀ��ʲ�����ް����ӷ� \n",
	 "���������˵�����з��޷�����������\n",
	 "�����˵�������޾ȿ���ѹ����й�����������\n",
	     (: random_move :)
        }) );
	setup();
	add_money("coin", 10+age/10);
}
	
