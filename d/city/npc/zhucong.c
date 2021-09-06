// zhucong.c wzfeng by 98-10-14
// Modify By River 98/10
// Modify by snowman@SJ 23/02/2000
// use steal command.

#include <ansi.h>

inherit NPC;
void greeting(object ob);
void create()
{
	set_name("���", ({ "zhu cong", "zhu", "cong"}));
	set("nickname", YEL"��������"NOR);
	set("title","��������");
	set("long", "���ǽ��������е�����������һ���������ר���򱧲�ƽ��\n");
	set("gender", "����");
	set("attitude", "friendly");
	set("unique", 1);
	set("location", 1);
	set("stealer_no_hold", 1);
	set_temp("wdj/�ⶾһ", 1);

	set("age", 28);
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
	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :),
	}));

	setup();
	if(clonep()){
		UPDATE_D->get_cloth(this_object());
		remove_call_out("do_back");
		call_out("do_back", 60);
	}
}

void init()
{
	object ob = this_player();
	::init();

	if ( living(ob) && !is_fighting() && !is_busy()){
		greeting(ob);
	}
	add_action("do_hit", "hit");
}

int steal_object(object ob)
{
	if( ob->query("unique") && !ob->is_character())
		return 1;
	return 0;
}

void greeting(object ob)
{
	object *inv;

	if( environment(ob) != environment()
	 || wizardp(ob)) return;

	if( ob->query("id") == query_temp("last_target")){
		delete_temp("last_target");
		return;
	}

	inv = deep_inventory(ob);
	if(!sizeof(inv)) return ;

	inv = filter_array(inv, (:steal_object:) );
	if(!sizeof(inv)) return;

	set("chat_chance", -1);
	if( command("steal "+inv[random(sizeof(inv))]->query("id")+" from "+ob->query("id")))
	ob->add_busy(2);

	set_temp("last_target", ob->query("id"));
	remove_call_out("do_back");
	call_out("do_back", 3+random(2), ob->query("id"));

	return;
}

void do_tell(string id)
{
	command("tell "+id+" лл���������ǲ�����˼��");
}

int accept_fight(object me)
{
	command("say �������յ�΢���Ǹ���"+RANK_D->query_respect(me)+"��ǰ�׳�");
	return 0;
}

void do_back(string id)
{
	string str;
	switch(query_temp("steal")){
		case 1: message_vision("$NȻ��ת��ͷȥ��������Ц��Ц��\n"NOR, this_object());
			if( id && id != this_object()->query("id")) call_out("do_tell",2 ,id);
			break;
		case -1: command("say ��λ���������������ǡ��������δ����������ѽ��������������"); break;
		default: break;
	}
	message_vision("һ����$N��֪���ﵽ����ȥ�ˡ�\n", this_object());
	set("chat_chance", 20);
	switch(random(66)){
		case 0:		str = "/d/cangzhou/kezhan";		break;
		case 1:		str = "/d/chengdu/center";		break;
		case 2:		str = "/d/city/xidajie3";		break;
		case 3:		str = "/d/city/guangchangbei";		break;
		case 4:		str = "/d/dali/dalics";			break;
		case 5:		str = "/d/dali/wangfu/nuange";		break;
		case 6:		str = "/d/dali/yuxu/yuxuguan";		break;
		case 7:		str = "/d/emei/huazangangc";		break;
		case 8:		str = "/d/emei/qingyinge";		break;
		case 9:		str = "/d/emei/qingshijie";		break;
		case 10:	str = "/d/fairyland/dating";		break;
		case 11:	str = "/d/foshan/guangchang";		break;
		case 12:	str = "/d/foshan/duchang";		break;
		case 13:	str = "/d/fuzhou/zhongxin";		break;
		case 14:	str = "/d/gb/pomiao";			break;
		case 15:	str = "/d/gumu/jqg/shiwu";		break;
		case 16:	str = "/d/gumu/jishi";			break;
		case 17:	str = "/d/hengshan/baiyunan";		break;
		case 18:	str = "/d/hengshan/beiyuemiao";		break;
		case 19:	str = "/d/hj/pmchang";			break;
		case 20:	str = "/d/hmy/qlongtang";		break;
		case 21:	str = "/d/hmy/pingding/kedian";		break;
		case 22:	str = "/d/huanghe/yyd/dating";		break;
		case 23:	str = "/d/lanzhou/bingcao";		break;
		case 24:	str = "/d/huashan/yunu";		break;
		case 25:	str = "/d/huashan/path1";		break;
		case 26:	str = "/d/hz/tianxiang";		break;
		case 27:	str = "/d/jiaxing/dating";		break;
		case 28:	str = "/d/kunlun/sanshengtang";		break;
		case 29:	str = "/d/miaojiang/woshi";		break;
		case 30:	str = "/d/mingjiao/shanjiao";		break;
		case 31:	str = "/d/mingjiao/sht";		break;
		case 32:	str = "/d/mingjiao/lsd/shanfeng";	break;
		case 33:	str = "/d/mingjiao/hdg/xfang4";		break;
		case 34:	str = "/d/mr/yanziwu/yanziwu";		break;
		case 35:	str = "/d/mr/mtl/cl3";			break;
		case 36:	str = "/d/nanyang/jxzhuang";		break;
		case 37:	str = "/d/ningbo/kedian";		break;
		case 38:	str = "/d/putian/guangchang";		break;
		case 39:	str = "/d/shaolin/pingtai";		break;
		case 40:	str = "/d/sld/dt";			break;
		case 41:	str = "/d/songshan/yushu-lou";		break;
		case 42:	str = "/d/suzhou/canglangting";		break;
		case 43:	str = "/d/taishan/shengxian";		break;
		case 44:	str = "/d/tanggu/center";		break;
		case 45:	str = "/d/thd/jicui";			break;
		case 46:	str = "/d/thd/guiyun/lianwuchang";	break;
		case 47:	str = "/d/thd/niujia/bay";		break;
		case 48:	str = "/d/tianshan/jtbu";		break;
		case 49:	str = "/d/tiezhang/wztang";		break;
		case 50:	str = "/d/tls/gfd";			break;
		case 51:	str = "/d/village/zhongxin";		break;
		case 52:	str = "/d/wudang/sanqing";		break;
		case 53:	str = "/d/wudang/jindian";		break;
		case 54:	str = "/d/xiangyang/cross1";		break;
		case 55:	str = "/d/xiangyang/damen";		break;
		case 56:	str = "/d/xiangyang/lzz/zhengt";	break;
		case 57:	str = "/d/xingxiu/ryd1";		break;
		case 58:	str = "/d/xingxiu/jyg";			break;
		case 59:	str = "/d/xueshan/guangchang";		break;
		case 60:	str = "/d/xueshan/zanpugc";		break;
		case 61:	str = "/d/xueshan/caoyuan/dazhang";	break;
		case 62:	str = "/d/jiaxing/tieqiang";		break;
		case 63:	str = "/d/huanghe/fendi";		break;
		case 64:	str = "/d/changan/zhonglou";		break;
		case 65:	str = "/d/tanggu/gangkou";		break;
		default:	str = "/d/city/guangchang";		break;
	}

	this_object()->move(str);
	this_object()->reincarnate();
	this_object()->clear_condition();

	message_vision(HIW"\n$N���Ҵҵ����˹�����\n"NOR, this_object());
	if(this_object()->query_temp("steal") > 0)
		command("say �ٺ٣�������ջ񲻴��");
	this_object()->delete_temp("steal");

}

void kill_ob(object me)
{
	command("say û�뵽�������˴��ҵ����⣡");
	remove_call_out("do_flee");
	call_out("do_flee", 1);
	::kill_ob(me);
}

int do_hit(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if((arg==("zhu"))||(arg==("zhu cong"))){
		command("say ��Ӵ��͵Ϯ�ҡ�");
		remove_call_out("do_flee");
		call_out("do_flee", 1);
		COMBAT_D->do_attack(me, ob, me->query_temp("weapon") );
		COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
		me->fight_ob(ob);
		ob->fight_ob(me);
		return 1;
	}
	return 0;
}

int do_flee()
{
	object ob = this_object();
	if(ob->query("qi")<(ob->query("max_qi")/2)){
		command("say �ҿ�û�����ٺ���ȥ�ˣ�Ҫ��ȡ�ҵ��������´ΰɡ�");
		ob->remove_all_killer();
		do_back(query("id"));
		return 1;
	}
	if(ob->is_fighting()){
		remove_call_out("do_flee");
		call_out("do_flee", 1);
	}
	return 1;
}

void unconcious()
{
	command("faint");
	do_back(query("id"));
}

void die()
{
	unconcious();
}


