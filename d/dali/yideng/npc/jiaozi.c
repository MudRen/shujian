// ���� by River@SJ 2002.6.5

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("����", ({ "jiao zi", "jiao", "zi" }) );
	set("long", "������ɫ��׳����̬������������������Ǵ󽫾��а������硣\n"+
		"�������ֲ����Ѷ�����ɽ�ּ��Բ񣬱ص����Ǹ�߳����Ƶ�ͳ����˧��\n");
	set("gender", "����" );
	set("age", 45);
	set("str", 30);
	set("con", 30);
	set("dex", 25);
	set("int", 25);
	set("per", 25);
	set("unique", 1);
	set("attitude", "friendly");

	set("max_qi", 5000);
	set("max_jing", 2800);
	set("eff_jingli", 3600);
	set("neili", 8000);
	set("qi", 5000);
	set("jingli", 3600);
	set("max_neili", 8000);
	set("jiali", 50);

	set("combat_exp", 2300000);
	set("score", 5000);

	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("axe", 280);
	set_skill("literate", 200);
	set_skill("qiantian-yiyang", 280);
	set_skill("pangen-fu", 280);
	set_skill("tianlong-xiang", 280);
	set_skill("finger", 200);
	set_skill("yiyang-zhi", 200);
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "pangen-fu");
	map_skill("force", "qiantian-yiyang");
	map_skill("finger", "yiyang-zhi");
	map_skill("axe","pangen-fu");
	prepare_skill("finger","yiyang-zhi");

	setup();
	carry_object(BINGQI_D("axe"))->wield();
	carry_object(ARMOR_D("b_cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}

void init()
{
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;

	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer", "answer");
}

void greeting(object me)
{
	if (! me || me->query_temp("yideng/answer")) return;
	command("say ������ϣ�ƾ��ң����������������ɥ�����Բԣ�ˮãã����̨\n"+
		"�������˽���ǧ��תͷ������������Ҳ���ó�������Ҳ���ó���");
	remove_call_out("greeting1");
	call_out("greeting1", 5, me);
}

void greeting1(object me)
{
	if (! me) return;
	command("say ������ۣ�������ŭ��ɽ�ӱ�������·���������������顣����\n"+
		"�غ����д���������䶼���������ˣ����տ࣡�������տ࣡");
	me->set_temp("yideng/answer", 1);
}

int do_answer(string arg)
{
	object me = this_player();

	if (! me->query_temp("yideng/answer")) return 0;
	if ( me->query_temp("yideng/jiaozi_pass")) return 0; 

	if ( ! arg ) return 0;

	if ( arg != "��ɽ����������మ���β��������۹��ƽ����һéի��Ұ����������˭���˷�˭�ɰܣ�ª�ﵥư�����ա�ƶ�������ģ��־���ģ�"){
		command("shake");
		return 1;
	}

	message_vision(CYN"\n$N�ص�������ɽ����������మ���β��������۹��ƽ����һéի��Ұ������\n"+
		"����˭���˷�˭�ɰܣ�ª�ﵥư�����ա�ƶ�������ģ��־���ģ���\n"NOR, me);

	message_vision(CYN"\n$N�������д��ã��Ŀ�����֮�ʣ���ɽ��һָ��������ȥ�գ�\n"NOR, this_object());
	me->set_temp("yideng/jiaozi_pass", 1);
	return 1;
}
