// le.c ��ɽ�ɵ��������� �ֺ�
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;

int ask_here();
int ask_idea();
int ask_yy();
int ask_yy2();
void create()
{
        set_name("�ֺ�", ({ "le hou", "le", "hou" }));
        set("nickname", HIC"��������"NOR);
        set("long", "���˰������֣���Ƥ���ף���ʮ������ͣ���ɽ�ɵ�һ�����֡�\n");
        set("gender", "����");
        set("age", 46);
        set("per", 17);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 29);
        set("int", 23);
        set("con", 23);
        set("dex", 23);
        set("unique", 1);

        set("max_qi", 3000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("shen", -13000);

	set_skill("force", 150);
	set_skill("hanbing-zhenqi", 150);
	set_skill("dodge", 150);
	set_skill("zhongyuefeng", 150);
	set_skill("hand", 160);
	set_skill("songyang-shou", 160);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("songshan-jian", 150);
	set_skill("literate", 100);
	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-jian");
	map_skill("sword", "songshan-jian");
	prepare_skill("hand", "songyang-shou");
	create_family("��ɽ��", 3, "����");
	set("inquiry", ([
                "here": (: ask_here() :),
                "����": (: ask_idea() :),
                "��������": (: ask_yy() :),
                "�������־���": (: ask_yy2() :),
                "����": (: ask_yy2() :),
		"��ɽ��" : "������ɽ������������֮�ף�\n",
		"��������" : "������������������֮�������޴󣬿������֡��䵱���⡣\n",
		"������" : "���������ǵ������ˣ�������ɲ⡣\n",
	]) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "hand.yinyang" :),
        }));
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
}

int ask_here()
{
	object me = this_player();

	if (!me->query_temp("ss/zsb_3") || me->query_skill("dodge")<250){
		command("say �����Ǵ�����Ͽ���˴������ն�"+RANK_D->query_respect(me)+"����ò�Ҫ�ڴ˾�����");
		return 1;
	}
	me->delete_temp("ss/zsb_3");
	me->set_temp("ss/zsb_4",1);
	command("say �����Ǵ�����Ͽ���˴������ն񣬵�����ʦ����һ�����ɱ޴��������ȥ��Ҳû���һ�����");
	command("whisper "+me->query("id")+" ������ҵ���һ������������ȥ����֪"+RANK_D->query_respect(me)+"��Ըǰ����");
	return 1;
}

int ask_idea()
{
	object me = this_player();

	if (!me->query_temp("ss/zsb_4")){
		command("? " + me->query("id"));
		return 1;
	}
	if (me->query_skill("dodge") < 250){
		command("say "+RANK_D->query_respect(me)+"������Ṧ��Ϊ̫����������¹ȡ�");
		return 1;
	}
	if (me->query_skill("force") < 250){
		command("say "+RANK_D->query_respect(me)+"��Ͽ���ں����쳣�������������ں����࿹�⡣");
		return 1;
	}
	me->delete_temp("ss/zsb_3");
	me->set_temp("ss/zsb_4",1);
	command("whisper "+me->query("id")+" ����ɽ����֦��������ֻ��Ҫ�Ҽ�֦��֦����������Ϳ����¹��ˡ�");
	return 1;
}

int ask_yy()
{
	object me = this_player();

	if (!me->query("family") || me->query("family/family_name") != "��ɽ��"){
		command("say "+RANK_D->query_respect(me)+"�������ҵľ��������������ɵġ�");
		return 1;
	}
	command("say "+RANK_D->query_respect(me)+"���ҵĴ������־������ǿ��������书��һ�����ģ�");
	me->set_temp("ss/yy1",1);
	return 1;
}

int ask_yy2()
{
	object me = this_player();
	object ob = this_object();

	if (!me->query_temp("ss/yy1")){
		command("say "+RANK_D->query_respect(me)+"��������ʲô��˼��");
		return 1;
	}
	if (!me->query("ss/yy")){
		if (me->query_skill("songyang-shou",1) < 120){
			command("say "+RANK_D->query_respect(me)+"���㹦��̫������������ѧ�ᣡ");
			return 1;
		}
		message_vision("$N��$n��������˵�˼��仰��\n",ob,me);
		tell_object(me,HIY"�ֺ��漴�������ֵľ���Ϥ���������㣬������ѧ���˴������֣�\n"NOR);
		me->set("ss/yy",1);
		me->delete_temp("ss/yy1");
		return 1;
	}
	else{
		command("say "+RANK_D->query_respect(me)+"�����Ѿ������˴������־����ľ�����ѽ��");
		return 1;
	}
}

#include "app3.h";