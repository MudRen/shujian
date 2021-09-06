// zayilama1.c ��������
// by iceland

#include <ansi.h>
inherit NPC;
#include "name.h";

int give_food();

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

      set_name(name, ({"zayi lama","lama","zayi"}));
	set("long",@LONG
���Ǵ����µ��������ֻ��Щ��ǳ���������������ͣ��ճ���Щ�ֻ��ػ
LONG
	);

	set("gender", "����");
	set("attitude", "heroism");
	set("title" , HIW"��������������"NOR);
	set("age", random(20)+20);
	set("shen_type", 0);
	set("str", random(10)+10);
	set("int", 20);
	set("con", random(10)+10);
	set("dex", random(10)+10);
	set("max_qi", 200);
	set("eff_jing", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("combat_exp", random(10000)+1000);
	set("unique", 15);

	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("unarmed", 10);
	set_skill("parry", 10);
        set("tea_count", 40);
        set("inquiry", ([ 
	       "ʳ��" : (: give_food :),
       ]) );

	setup();
        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int give_food()
{
       object food, me, ob;

       me = this_object();
       ob = this_player();

       if ( objectp(present("suyou cha", (ob))))  { 
	  command("say �����ϲ��ǻ���ô���ȳ�����������Ҫ�ɡ���");
          return 1;  } 

        if (query("tea_count") < 1)  { 
	  command("say ������������Ǻ�����ʳ�ﶼ�Թ��ˣ��������ڼӽ��������Ե�һ�ᡣ��");
          return 1;  } 

       food = new(FOOD_D("youcha"));
       food->move(ob);

       message_vision("$N����$nһ�����Ͳ衣\n", me, ob);
// 98         add("tea_count", -1);
       return 1;
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return; 
        command("say "+ RANK_D->query_respect(ob) + "�ǲ��Ƕ��ˣ�������˿�������Ҫʳ��(ask lama about ʳ��)��\n");
 }
