// worker.c Ů��

#include <ansi.h>
inherit NPC;
#include "name.h" ;
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
	set_name(name, ({ "nv gong","nvgong","nv","gong"}));
	set("age", random(30)+14);
	set("gender", "Ů��");
	set("long", "����������Ƽ��ݣ����嵥����һ����֪��������ˡ�\n");
	set("attitude", "peaceful");
        set("title","��ެ֯������Ů��");

	set("str", 15);
	set("dex", 10);
	set("combat_exp", random(1000)+100);
	set("shen_type", 1);
	set("unique", 2);

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);

	setup();
	carry_object(ARMOR_D("pipao"))->wear();
}
