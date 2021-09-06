
#include <ansi.h>
inherit NPC;

int do_look(string);
int ask_me();
string ask_skill();

void create()
{
	object ob;
	set_name("��Ī��", ({ "li mochou", "li", "mochou" }));
	set("long", "�����ü�Ϊ��ò���������Ŀ�����˲���������\n");
	set("nickname", HIR"��������"NOR);
	set("gender", "Ů��");
	set("rank_info/respect", "����");
	create_family("��Ĺ��", 3, "����");

	set("age", 27);
	set("attitude","heroism");
	set("str", 22);
	set("dex", 23);
	set("con", 20);
	set("int", 24);
	set("shen_type", -1);

	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("sword", 150);
	set_skill("throwing",100);
	set_skill("poison", 50);
	set_skill("meinu-quanfa", 150);
	set_skill("cuff", 150);
	set_skill("meinu-quanfa", 150);
	set_skill("yunu-shenfa", 150);
	set_skill("yunu-jianfa", 150);
	set_skill("yunu-xinjing", 150);
	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "yunu-shenfa");
	map_skill("cuff", "meinu-quanfa");
	map_skill("sword", "yunu-jianfa");
	prepare_skill("cuff", "meinu-quanfa");
	set("jiali", 30);

	set("combat_exp", 1100000);
        set("max_qi", 8000);
	set("max_jing", 2200);
	set("eff_jingli", 2000);
	set("neili", 3500);
        set("max_neili", 3500);
        set_temp("apply/dodge", 180);
        set_temp("apply/armor", 200);
	set("inquiry", ([
		"name" : "վԶ�㣡",
		"here" : "�Ҳ��Ǳ����ˣ���֪����",
		"��" : "����������������˼֮�ࡢ���֮�⣿",
		"½չԪ" : "�����Ǹ������С������ʲô��",
		"�����" : (: ask_me :),
		"����������" : (: ask_skill :),
		"С��Ů" : "�����ҵ�ʦ�á����������ʲô��",
		"�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",
	]));

	set("chat_chance", 2);
	set("chat_msg", ({
		"��Ī���������裬�������񣬸�����������䣬���Ǻ��ֱ������������\n",
		"��Ī�����������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
		"��Ī�����������Ȥ�����࣬���и��гն�Ů����\n",
		"��Ī���������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
		"��Ī����Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������\n",
		"��Ī���������л�Щ��ർ���ɽ��������ꡣ��\n",
		"��Ī���������Ҳ�ʣ�δ���ˣ�ݺ�����Ӿ��������\n",
		"��Ī�������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
	}));
	setup();
	if (clonep()) {
		ob = unew(BINGQI_D("sword/zhen"));
		if (!ob) ob = unew(BINGQI_D("changjian"));
		ob->move(this_object());
		ob->wield();
		carry_object(BINGQI_D("bb_zhen"));
       	carry_object(BINGQI_D("bb_zhen"));
    	carry_object(BINGQI_D("bb_zhen"));
    	carry_object(BINGQI_D("bb_zhen"));
    	carry_object(BINGQI_D("bb_zhen"));
    	carry_object(BINGQI_D("bb_zhen"));
    	carry_object(BINGQI_D("bb_zhen"));
		carry_object("/d/wudang/obj/greenrobe")->wear();
	}
}

void init()
{
	::init();
	add_action("do_look","look");
	add_action("do_look","hug");
	add_action("do_look","mo");
	add_action("do_look","18mo");
	add_action("do_look","kiss");
	add_action("do_look","lean");
	add_action("do_look","interest");
	add_action("do_look","flirt");
	add_action("do_look","pretty");
	add_action("do_look","love");
}

int ask_me()
{
	object me;

	me = this_player();
	message_vision(HIR "��Ī����Цһ���������������ȥ��������\n"NOR, me);
	kill_ob(me);
	return 1;
}

string *wheres=({
"/d/emei/xiaowu",		"/d/wudang/xiaolu1",		"/d/xiangyang/zhuquemen",
"/d/xiangyang/hanshui1",	"/d/fuzhou/road1",		"/d/xueshan/xuelu2",
"/d/xueshan/houzidong",		"/d/suzhou/lingyansi",		"/d/suzhou/liuyuan",
"/d/jiaxing/tieqiang",		"/d/hz/longjing",		"/d/hz/huanglong",
"/d/hz/yuhuang",		"/d/hz/tianxiang",		"/d/miaojiang/jiedao4",
"/d/foshan/duchang",		"/d/huanghe/shulin5",		"/d/hz/changlang1",
"/d/hz/yuquan",			"/d/hz/longjing",		"/d/xingxiu/shamo3",
"/d/wudang/xuanyue",		"/d/emei/guanyinqiao",		"/d/emei/basipan3",
"/d/tiezhang/shanmen",		"/d/tiezhang/hclu",		"/d/xueshan/huilang4",
"/d/emei/caopeng",		"/d/mingjiao/bishui",		"/d/mingjiao/shanting",
"/d/fuzhou/haigang",		"/d/fuzhou/laozhai",		"/d/xingxiu/shamo2",
"/d/jiaxing/nanhu",		"/d/village/caidi",		"/d/shaolin/songshu2",
"/d/xiangyang/tanxi",		"/d/huashan/husun",		"/d/huashan/yunu",
"/d/mr/yanziwu/xiaojing2",	"/d/mr/mtl/liulin",		"/d/suzhou/shihu",
"/d/suzhou/xuanmiaoguan",	"/d/suzhou/zijinan",		"/d/hengshan/cuiping2",
"/d/hengshan/guolaoling",	"/d/shaolin/talin1",		"/d/wudang/houshan/husunchou",
"/d/shaolin/shanlu8",		"/d/xueshan/shanlu7",		"/d/foshan/road10",
"/d/foshan/xiaolu2",		"/d/emei/jiulaodong",		"/d/hengshan/beiyuemiao",
"/d/gb/xinglin2",		"/d/city/shangang",		"/d/fuzhou/zhongxin",
"/d/huanghe/huanghe4",		"/d/lanzhou/shamo",		"/d/emei/gudelin3",
"/d/cangzhou/dongjie1",		"/d/tanggu/center",		"/d/putian/xl6",
"/d/dali/wuliang/songlin6",	"/d/gumu/xuantie/linhai8",	"/d/gumu/jqg/zhulin5",
});

string ask_skill()
{
	object me = this_player();
	object ob,room;
	int p, y=0;

	if (!me->query("family")
	 ||  me->query("family/family_name") != "��Ĺ��"){
		command("sneer "+ me->query("id"));
		return "���������������û�й�Ĺ���ڹ�֧�֣�Ҳ�޷�����͸������ѧ��Ҳ���á�";
	}
	if ( me->query_skill("meinu-quanfa", 1) < 120 ){
		command("sneer "+ me->query("id"));
		return RANK_D->query_respect(me) + "����Ůȭ��������������ѧ��Ҳ���á�";
	}
	if ( me->query_skill("yinsuo-jinling", 1) < 120 ){
		command("sneer "+ me->query("id"));
		return RANK_D->query_respect(me)+"���������廹����������ѧ��Ҳ���á�";
	}
	if( me->query_temp("limochou/ask") && !wizardp(me))
		return "�Ҳ����Ѿ���������ô��������ȥ�����һء��嶾�ش�����";

	if(me->query("gmsanwu") && !wizardp(me)){
		command("? " + me->query("id"));
		return "�㲻���Ѿ�ѧ��������������ô��";
	}

	y = sizeof( filter_array(children(__DIR__"lu"),(:clonep:)));
	if(y > 0)
		return "��ʱ��û�������Ȥ�����ȥ�ɡ�";

	p = random(sizeof(wheres));
	room= find_object(wheres[p]);
	if(!objectp(room)) return "��ʱ��û�������Ȥ�����Ȼ�ȥ�ɣ�";
	ob= new(__DIR__"lu");
	ob->move(room);
	me->set_temp("limochou/ask", 1);
	message_vision(CYN"��Ī��¶��һ����Թ��֮ɫ��\n"NOR,me);
	return "���Ǳ����嶾�ش�����½��˫��С���˸�͵���ˣ�������ܰ����һش��飬�Ҿʹ��������������֡�";
}

int accept_object(object who, object ob,object me)
{
	me= this_object();

	if( ob->query("id") != "wudu mizhuan"){
		command("say ������ⶫ������");
		return 0;
	}
	if( ob->query("owner") != who->query("id")
	 || !who->query_temp("limochou/ask")){
		command("haha");
		command("say ��л"+RANK_D->query_respect(who) + "��æ��СŮ�Ӷ�л�ˡ�");
		who->delete_temp("limochou");
		call_out("dest", 1, ob);
		return 1;
	}
	command("say �ðɣ����Ҿʹ��������������ֵ��ķ��ɡ�");
	command("whisper "+ who->query("id")+ " �޿ײ��롢����������������Ϊ��");
	who->set("gmsanwu", 1);
	who->delete_temp("limochou");
	call_out("dest", 1 ,ob);
	return 1;
}

void dest(object obj)
{
	if(! obj) return;
	destruct(obj);
}

int do_look(string target)
{
	object me;

	me = this_player();
	if ( target
	&& present(target, environment()) == this_object()
	&& living(this_object()) 
    &&!me->query_temp("lmc/throw"))
                if ((string)me->query("gender") == "����" && me->query("combat_exp") >=200000) {
                        message_vision(HIR "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n"
					"��Ī�����ɱ��$N��\n"NOR, me);
			if ( present("bingpo yinzhen", this_object()) && ! this_object()->is_busy())
				me->set_temp("lmc/throw", 1);
			command("throw yinzhen at " + me->query("id"));
			kill_ob(me);
		}
}

void kill_ob(object me)
{
	command("haha");
        if ( present("bingpo yinzhen", this_object()) && ! this_object()->is_busy())
                me->set_temp("lmc/throw", 1);
	command("throw yinzhen at " + me->query("id"));
	::kill_ob(me);
}
