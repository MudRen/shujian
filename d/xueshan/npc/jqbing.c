// jqbing.c ʿ��

#include <ansi.h>
inherit NPC;
#include "name.h";
#include "cike.h";

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
	set_name(name, ({ "qi bing", "qibing" ,"bing","qi"}));
	set("age", random(10)+20);
	set("gender", "����");
	set("long", "�������ɹ�������������¼�����������������ò�뺷���������֮����\n");
	set("attitude", "heroism");
        set("title",HIY"����Ӫ���"NOR);

	set("str", random(10)+15);
	set("dex", random(10)+20);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("unique", 5);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 60);

	setup();
	carry_object(BINGQI_D("madao"))->wield();
	carry_object(ARMOR_D("pixue"))->wear();
	carry_object(ARMOR_D("pijia"))->wear();
}
