// zhou-zhiruo.c
// Lklv 2001.10.18 update hehe С�

inherit F_MASTER;
inherit NPC;

int ask_zhang();
int ask_dragon();

void create()
{
	set_name("������", ({ "zhou zhiruo", "zhou", "zhiruo"}));
	set("long", "�������ʦ̫�İ˴��׼ҵ���֮һ��һ����ɫ�������Եĳ������ˡ�\n");
	set("gender", "Ů��");
	set("attitude", "friendly");
	set("age", 25);
	set("shen_type", -1);
	set("str", 42);
	set("int", 42);
	set("con", 42);
	set("dex", 42);
	set("per", 40);

        set("max_qi", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 1500000);
        set("score", 100);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "claw.jiuyin" :)
	}));

        set_skill("literate", 180);
	set_skill("sword", 80);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("force", 180);
        set_skill("strike", 180);
        set_skill("claw", 180);
        set_skill("anying-fuxiang", 180);
        set_skill("jiuyin-baiguzhua", 180);
	set_skill("huifeng-jian", 80);
        set_skill("dacheng-fofa", 180);
        set_skill("linji-zhuang", 180);

        set("apply/attack", 50);
        set("apply/dexerity", 50);

        map_skill("force", "linji-zhuang");
        map_skill("parry", "jiuyin-baiguzhua");
        map_skill("claw", "jiuyin-baiguzhua");
        map_skill("sword", "huifeng-jian");
        map_skill("dodge", "anying-fuxiang");
        prepare_skill("claw", "jiuyin-baiguzhua");

        set("inquiry",([
		"���޼�" : (: ask_zhang :),
//		"����" : (: ask_zhao :),
		"������" : (: ask_dragon :),
		"�������" : (: ask_dragon :),
        ]) );
        create_family("������", 4, "����");

        setup();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if (! ob->query("family")) {
		command("say ����Ҷ����ɵ��ӣ��Ҳ������㡣\n");
		return;
        }
        if ((int)ob->query_skill("claw", 1) < 41 ) {
		command("say �����צ�����δ�����Ҳ������㡣\n");
		return;
        }
        if ((int)ob->query_skill("strike", 1) < 41 ) {
		command("say ������Ʒ����δ�����Ҳ������㡣\n");
		return;
        }
	if (ob->query("class") == "bonze"){
		command ("blush");
		command ("say ��ֻ���׼ҵ��ӡ�");
		return;
	}
        if ((int)ob->query_skill("jiuyin-baiguzhua", 1) < 41 ) {
		command("say �����ڲ�����ͽ��\n");
		return;
        }
        command("recruit " + ob->query("id"));
        command("chat* grin");
        command("grin");
}

int ask_zhang()
{
	object me=this_player();
	if( me->query_temp("jiuyin140") == 2 ) {
		command("blush");
		command("say ��Ȼ���Ѿ����Ĳ���ϲ������������Ӱ����ʱ�޿̲��������ҵ��Ժ��\n");
		command("say ���վ�������ƭ�Լ�����������ƭʦ����ʦ���̸��ҵ��������������ܺ͹�����ɵ��뷨�վ��ǲ���ʵ���ˡ�\n");
		command("sigh");
		me->set_temp("jiuyin140", 3 );
		return 1;
	}
	message_vision("����������$Nһ�ۡ�\n", me);
	return 1;
}

int ask_dragon()
{
	object me=this_player();
	if( me->query_temp("jiuyin140") >= 3 ) {
		if( me->query("family/master_name") != "������"
	 	 && !me->query_skill("jiuyin-baiguzhua",1) ) {
			command("say �����ڲ����ҵ�ͽ�ܣ�Ҳû�д�������ѧ��ʲô��������ƾ�����ڵ��书����������������ģ�Ҳ�͸�̸���Ϲ������ˡ�\n");
			return 1;
		}
		command("say ��Ȼ��ˣ��㵽��ʦ������ѯ���������������ܰɡ�\n");
		command("say �����ҵ�ϣ��ֻ�ܼ��������ˡ�\n");
		command("sigh");
		me->set_temp("jiuyin140", 4 );
		return 1;
	}
	message_vision("�����������ؿ���$Nһ�ۣ�ҡ��ҡͷ��\n", me);
	return 1;
}
