// duke.c

inherit NPC;
#include "name.h";

void create()
{
    string name,m1,m2,m3,m4;
    int i;
    i=random(4);
m1=names[i][random(sizeof(names[i]))];	
m2=names[0][random(sizeof(names[0]))];
m3=names[1][random(sizeof(names[1]))];
m4=names[2][random(sizeof(names[2]))];

switch (random(3)){
	case 0:  
        name = m1+m2; 
 	break;
	case 1: 
        name = m1+m2+m3; 
	break;
	case 2:
        name = m1+m2+m3+m4 ;  
	break;
	} 

        set_name(name, ({"du ke", "ke","duke" }) );
        set("gender", "����" );
        set("age", 35);
        set("long", "���Ǹ��������õĶĿͣ�˫�۰���ͨ�죬����Ѫ˿��\n");

        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 1000);
	set("shen_type", 0);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");
        setup();
        set("chat_chance", 5);
        set("chat_msg", ({
		name+"�����Ϳڴ�����������ͭ������\n",
                name+"��һ�������������ۣ�ͨɱ����\n",
		name+"���ͷ��ĺ����������Ѻѽ�������������������������ӮЩ�ء�\n",
        }) );
        carry_object(ARMOR_D("pipao"))->wear();
        add_money("coin", 100);
}
