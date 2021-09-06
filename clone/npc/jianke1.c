// jian-ke.c By River@SJ 2002.4.24

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("����", ({ "jian ke", "jian", "ke"}));
	set("long", "����λ�������ˣ��米�����������Ľ������Ʈ������ƺ������ա�\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("unique", 1);
	set("location", 1);
	set("no_quest", 1);
	set("stealer_no_hold", 1);
	set_temp("wdj/�ⶾһ", 1);
	set("env/invisibility", 10);

	set("age", 38);

	set("per",20);
	set("kar", 30);

	set("shen", 5000);
	set("str", 30);
	set("int", 26);
	set("con", 25);
	set("dex", 23);

	set("max_qi", 2000);
	set("qi", 2000);
	set("max_jing", 1500);
	set("eff_jingli", 2000);
	set("jiali", 20);
	set("combat_exp",500000);

	set_skill("cuff", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("stealing", 200);
	set_skill("taizu-quan", 100);
	set_skill("zuibaxian", 100);
	set_skill("yinyun-ziqi", 100);
	set_skill("parry", 100);

	map_skill("force","yinyun-ziqi");
	map_skill("dodge","zuibaxian");
	map_skill("cuff","taizu-quan");
	map_skill("parry","taizu-quan");
	prepare_skill("cuff","taizu-quan"); 

	set_temp("apply/armor", 50);

	set("chat_chance", 100);
	set("chat_msg", ({
		(: random_move :),
	}));

	setup();
	if(clonep()){
		UPDATE_D->get_cloth(this_object());
		remove_call_out("do_back");
		call_out("do_back", 25, this_object());
	}
}

void do_back(object ob)
{
	string str;
	switch(random(18)){
		case 0:		str = "/d/thd/neishi1";			break;
		case 1:		str = "/d/hmy/guanpu";			break;
		case 2:		str = "/d/hmy/qqiudian";		break;
		case 3:		str = "/d/shaolin/xiaojing2";		break;
		case 4:		str = "/d/fuzhou/feiyuan";		break;
		case 5:		str = "/d/fuzhou/wroad8";		break;
		case 6:		str = "/d/miaojiang/slu8";		break;
		case 7:		str = "/d/miaojiang/shef";		break;
		case 8:		str = "/d/miaojiang/woshi";		break;
		case 9:		str = "/d/hengshan/baiyunan";		break;
		case 10:	str = "/d/foshan/dating";		break;
		case 11:	str = "/d/dali/daliwest/tianchi2";	break;
		case 12:	str = "/d/dali/wuliang/keting";		break;
		case 13:	str = "/d/dali/yideng/shiwu";		break;
		case 14:	str = "/d/dali/yideng/shanpo";		break;
		case 15:	str = "/d/thd/jicui";			break;
		case 16:	str = "/d/sld/dt";			break;
		case 17:	str = "/d/tianshan/jtbu";		break;
		default:	str = "/d/dali/dalieast/ydxxx";		break;
	}
	ob->move(str);
	ob->reincarnate();
	ob->remove_all_killer();
	ob->clear_condition();
	remove_call_out("do_back");
	call_out("do_back", 30, ob);
}

void heart_beat()
{
	::heart_beat();
	if ( this_object()->is_fighting())
		do_back(this_object());
}

void unconcious()
{
	do_back(this_object());
}

void die()
{
	unconcious();
}
