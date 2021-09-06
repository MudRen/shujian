// seng-ren.c ɮ��
// Lklv modify at 2001.10.21

#include <ansi.h>
inherit NPC;

string ask_me();
string ask_me1();
string ask_me2();

void create()
{
        set_name("�η�����", ({"seng ren","seng"}));
        set("long", "����һλ�����η����У����ϵ����Ĵ����˲�����\n");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 65);
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 25);
        set("dex", 23);
        set("max_qi", 280);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 150);
        set("combat_exp", 10000);
        set("shen_type", 0);
        set("chat_chance", 30);

        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	set("jing_count", 1);
	setup();
	carry_object("/d/shaolin/obj/cloth")->wear();
	set("inquiry", ([
		"name" : (: ask_me :),
		"here" : ( : ask_me1 :),
		"����" : (: ask_me2 :),
		"��վ�" : "��ʯƺ�����̼��ǽ�վ�,�������۾���������Ϊ�ľ���֮��.\n",
	]));
	setup();
}

void init()
{
        add_action("do_say", "say");
}

string ask_me()
{
	object me = this_player();

	if (me->query_temp("sl_wm1")){
		command("look "+me->query("id"));
		me->delete_temp("sl_wm1");
		me->set_temp("sl_wm2",1);
		return "���ķ�������������.\n";
	}
	return "���������ķ�,��������������.\n";
}

string ask_me1()
{
	object me = this_player();

	if (me->query_temp("sl_wm2")){
		command("look "+(string)me->query("id"));
		me->delete_temp("sl_wm2");
		me->set_temp("sl_wm3",1);
		return HIW"�˵���ʯ������ǰ����λ�ܹ��ɽ���żȻ�õ�һ�����Ľ�վ�������֮��
��ʱ�󳹴��򣬺���Ż��߿Ѫ��������׭����ڴ�ƺ֮�ϣ����Ը������ˣ�ʯƺ�깤֮ʱ��
��Ҳ�����ڴˡ����ĳ��ڴ�Ĭ��ʯ������������\n"NOR;
	}

	return "�˵���ʯ������ǰ����λ�ܹ��ɽ���żȻ�õ�һ�����Ľ�վ���
����֮���ʱ�󳹴��򣬺�����Ż��߿Ѫ��������׭����ڴ�ƺ֮�ϣ����Ը������ˣ�
ʯƺ�깤֮ʱ����Ҳ�����ڴˡ�\n";
}

string ask_me2()
{
	object me = this_player();

	if (me->query_temp("sl_wm3")){
		me->delete_temp("sl_wm3");
		me->set_temp("sl_wm4",1);
		return RANK_D->query_respect(this_player())+"�����ڴ�Ĭ����վ�,������������֮��.";
	}
	if (me->query_temp("sl_findjing")){
		command(":) "+(string)me->query("id"));
		me->set_temp("sl_wm5",1);
		me->delete_temp("sl_findjing");
		return HIW"��ǰ�и������ţ�����������Ϣ�����д���Ҫ����������������������
��������������ץ�ã������ų˻��Ѵ�����ֻǰ����������֮�ϣ��ܾͲ��ܶ��ˣ�������
��Ҳ���ҷ��֡�������һ�˾�����������������æ��һͬɱ�ܷ��⡣�������ˣ���ס����
������������Զ�ӣ����˷���Ϊ���������޷��������֪��Ԣ�⣿\n"NOR;
	}

	return RANK_D->query_respect(this_player())+"��֪���˵ص�����?";
}

int do_say(string arg)
{
	object me = this_player();

	if ((arg=="����Σ�ѣ��ܲ���������ǣ�ۣ��������ڡ�"
	 ||arg=="����Σ��,�ܲ�����,����ǣ��,��������."
	 ||arg=="����Σ�ѣ��ܲ���������ǣ�ۣ���������.")
	 && me->query_temp("sl_wm5")){
		if (query("jing_count") >= 1){
			me->delete_temp("sl_wm5");
			me->set_temp("sl_bookget",1);
			message_vision(HIW"$Nͦ�ش���˵����������Σ�ѣ��ܲ���������ǣ�ۣ��������ڡ���\n"NOR,me);
			message_vision(HIW"��ɮ�����ƺ�����һ�£�Ȼ��΢΢һЦ˵��,"+ RANK_D->query_respect(this_player())+"��������Ϊ�β��ߣ�\n"NOR,me);
			new(__DIR__"obj/f_jing")->move(me);
			add("jing_count", -1);
			return 1;
		}
		me->delete_temp("sl_wm5");
		message_vision("��ɮȻ��΢΢һЦ˵��������һ������"
		+ RANK_D->query_respect(this_player())+"�����Ѿ�����ȡ�ߣ��´������Ե�ɺϣ��������˽��۷𷨡�\n",me);
		return 1;
	}
}

void kill_ob(object ob)
{
       ob->remove_killer(this_object());
       remove_killer(ob);
       message_vision("$N�����η�ɮ����һЦ,˿��û��η��,��������һ����\n", ob);
}
