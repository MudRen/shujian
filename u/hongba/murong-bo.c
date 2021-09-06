// /u/leontt/npc/murong-bo.c  Ľ�ݲ�
// by leontt 1/5/2000

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_blade();
string ask_armor();
string ask_me();
string ask_me1();

void create()
{
        object weapon,armor;
        set_name("Ľ�ݲ�",({"murong bo","murong","bo"}));
        set("title","����Ľ����ү��");
        set("nick","�Ա�֮�� ��ʩ����");
        set("long",
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݲ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 57);
        set("attitude", "friendly");
        set("no_bark",1);
        set("shen_type", -1);

        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("per", 27);

        set("max_qi", 9500);
        set("max_jing", 7500);
        set("neili", 19500);
        set("max_neili", 19500);
        set("eff_jingli", 7000);
        set("jiali", 120);
        set("combat_exp", 4400000);
        set("score", 30000);
        set("chat_chance_combat", 80);

        set("chat_msg_combat", ({
                (: perform_action, "blade.daoying" :),
                (: perform_action, "strike.riyue" :),
	}));

        set_skill("xingyi-zhang", 360);
        set_skill("strike", 350);
        set_skill("finger", 350);
        set_skill("dodge", 350);
        set_skill("force", 370);
        set_skill("canhe-zhi", 370);
        set_skill("murong-jianfa",360);
        set_skill("shenyuan-gong", 360);
        set_skill("yanling-shenfa", 350);
        set_skill("douzhuan-xingyi", 380);
        set_skill("parry", 360);
        set_skill("sword", 360);
        set_skill("literate", 200);
        set_skill("murong-daofa", 360);
        set_skill("blade",360);
        set_skill("xingyi-jianzhen",200);

        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
        map_skill("force", "shenyuan-gong");
        map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "xingyi-zhang");
        map_skill("sword", "murong-jianfa");
        map_skill("strike", "xingyi-zhang");

        prepare_skill("strike","xingyi-zhang");

        create_family("����Ľ��",1,"����");

        set("inquiry",  ([
		"name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݲ���\n",
		"here" : "�����������µĲؾ�¥��\n",
		"rumors" : "���Ǹ���������֮�д�������ͷ����ү�����������ѽ��\n",
		"����" : (: ask_blade :),
		"�̲���¶��" : (: ask_blade :),
		"����" : (: ask_armor :),
		"��Ը" : (: ask_me :),
		"������ɮ" : "�����˼������书����������Ϊ���ѵ������ɲ�ľ���,�������ż��Ҳ��������һЩ��Ը.\n",
		"����" : (: ask_me1 :),
	]));

        set_temp("apply/damage", 50);
        set_temp("apply/dodge", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/armor", 40);

        setup();
        if (clonep()){
                weapon = unew(BINGQI_D("blade/lvbo-dao"));
                if(!weapon) weapon=new(BINGQI_D("blade"));
                weapon->move(this_object());
                weapon->wield();

                armor=unew("/clone/armor/longpao");
                if( ! armor) armor = new(ARMOR_D("cloth"));
                armor->move(this_object());
                armor->wear();
        }
        add_money("gold", 1);
}

void attempt_apprentice(object ob)
{
	object me  = this_player();

	string name, new_name;
	name = ob->query("name");

	if (present("jiaxin", me)) {
		destruct(present("jiaxin",me));
		command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "���Ҷ����ż�����Ϊ��" +
			"��������������Ҿ�������ɡ�");

		new_name = "Ľ��" + name[<4..<1];
		ob->set("name", new_name);
		command("say �ӽ��Ժ���ͽ���" + new_name + "��ϣ�����ܰ�Ľ�ݹ�������");
		command("recruit " + ob->parse_command_id_list()[0]);
		command("chat* ����һЦ��˭�� �Ա�֮�� ��ʩ���� ����������");
		command("chat* haha");
	}
	else
		command("say ��Ľ�ݲ����������ͽ!");
	return;
}

void reset()
{
	object ob;

	if (clonep() && (ob = unew(BINGQI_D("blade/lvbo-dao")))) {
		ob->move(this_object());
		command("wield lvboxianglu dao");
	}
	if (clonep() && (ob = unew(ARMOR_D("longpao")))) {
		ob->move(this_object());
		command("wear long pao");
	}
}

string ask_blade()
{
	object blade;
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";

	if (this_player()->query("combat_exp") < 150000)
		return RANK_D->query_respect(this_player())+"�����������������²��ܱ�ס��ѱ�����";

	if ( present("lvboxianglu dao", this_player()))
		return RANK_D->query_respect(this_player()) +
			"�̲���¶��ֻ��һ�ѣ����Ҿ��������ϣ�����̰�����ᣡ";

	if ( present("lvboxianglu dao", this_object())) {
		command("give lvboxianglu dao to "+this_player()->query("id"));
		blade = unew(BINGQI_D("blade"));
		if(clonep(blade)){
			blade->move(this_object());
			command("wield dao");
		}
		else{
			blade = unew(BINGQI_D("blade"));
			blade->move(this_object());
			command("wield dao");
		}
		return "������Ϊ��Ľ������Щ����ء��������׳�٣��Ų����Ҷ����һƬ����������̲���¶�����͸���ɣ�";
	}
	return "��Ǹ���������ˣ��ҵ��̲���¶���Ѹ�����ȡ���ˡ�";
}

string ask_armor()
{
        object armor;
        object me, ob;
        mapping fam;

        me = this_player();
        ob = this_object();

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����Ľ��")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
        if (this_player()->query("combat_exp") < 150000)
		return RANK_D->query_respect(this_player())+"�����������������²��ܱ�ס������ۡ�";
        if ( present("longpao", this_player()))
		return RANK_D->query_respect(this_player()) +
                "����ֻ��һ�������Ҿ��������ϣ�����̰�����ᣡ";
        if ( present("longpao", this_object())) {
        	command("give longpao to "+this_player()->query("id"));
		if(clonep(armor)){
			armor = unew(ARMOR_D("cloth"));
			armor->move(this_object());
			command("wear cloth");
		}
		else{
			armor = unew(ARMOR_D("cloth"));
			armor->move(this_object());
			command("wear cloth");
		}
		return "������Ϊ��Ľ������Щ����ء��������׳�٣��Ų����Ҷ����һƬ������������۾��͸���ɣ�";
	}
	return "��Ǹ���������ˣ��ҵ������Ѹ�����ȡ���ˡ�";
}

string ask_me()
{
        object me = this_player();

	mapping my_fam  = me->query("family");

	if (my_fam["generation"] == 35)
		return RANK_D->query_respect(this_player())+ "���ҹ�������,�ѵ�û���ô�ү������ǲ!";

	if (!(my_fam) || my_fam["family_name"] != "������" || my_fam["generation"] != 36
	 || (string)me->query("class")!="bonze" )
		return RANK_D->query_respect(this_player())+  "�������������书���Ǿ߼�֮��,�㲻֪��Ҳ��.";

	if (me->query_temp("sl_wm1"))
		return RANK_D->query_respect(this_player()) +  "�Ҳ��Ǻ���˵������?�㵱��Ľ�ݲ�ʲ����?";

	me->set_temp("sl_wm1",1);
	return "��ʦ��ż���ᵽ��������ʦ��������ʦ�������ȥѰ��һ����Ħ��ʦ��д�Ľ�վ�,\n"+
		"һȥ��ʮ����������,ʦ����̸���ƺ��йһ�֮��,��Ҳ��ȥ��̽������Ҳûʲ����Ϣ��";
}

string ask_me1()
{
	object me = this_player();

        if ( file_name(environment(this_object())) != this_object()->query("startroom"))
        	return "�����������棬���һ�ȥ��˵�ɡ�";

	if (!present("fanwen jing", me))
		return RANK_D->query_respect(this_player()) + "����û�о���,�������Ĵ�ڿ��?";
	command("nod");
	tell_room(me,HIY "Ľ�ݲ�����һ��,"+ me->name()
		+ "�·����Ƽ���һ��ɽ������ݡ�\n"NOR, ({ me }));
	write(HIY"�����һ���ھ�������������׽������ݡ�\n"NOR);

	me->move("/d/shaolin/liwu");
	return "�������,�����ӷ�.";
}
