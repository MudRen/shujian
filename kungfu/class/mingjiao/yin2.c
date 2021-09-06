// yin2.c ��Ұ��
// Modify By River@sj 99.06
// Modify By Looklove@sj 2000/9/17
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_xunluo();
string ask_yin();
void create()
{
        set_name("��Ұ��",({"yin yewang", "yin", "yewang"}));
        set("title","������ӥ�ֶ���΢������");
        set("long", "����ҡ���ȣ���·������ɳ���𣬱�������ˮ����Ʈ��һ�㡣\n"+
                    "�����̵����������һֻСС��ӥ��˫��չ��������ʮ����\n"+
                    "��ͣ���һ˫�۾�������磬�������䣬�������ˡ�������\n"+
                    "����ӥ�ֶ���΢���������������̽������׾˸���Ұ����\n");
        set("age", 41);
        set("no_bark",1);
        set("env/wimpy", 40);
        set("attitude", "peaceful");
        set("shen", -8000);
        set("str", 25);
        set("int", 22);
        set("con", 25);
        set("dex", 25);
        set("per", 24);
        set("unique", 1);        
        set("max_qi", 1500);
        set("max_jing", 1300);
        set("jiali", 50);
        set("combat_exp", 800000);        

	set_skill("hand",110); 
	set_skill("dodge",110);
	set_skill("force", 110);
	set_skill("literate",110);
	set_skill("blade", 110);
	set_skill("sword", 110);
	set_skill("piaoyi-shenfa", 110);
	set_skill("shenghuo-shengong", 110);
	set_skill("yingzhua-shou",110);
	set_skill("liehuo-jian",110);
	set_skill("lieyan-dao",110);
	set_skill("parry", 110);

	map_skill("blade", "lieyan-dao");
	map_skill("sword", "liehuo-jian");
	map_skill("force", "shenghuo-shengong");
	map_skill("dodge", "piaoyi-shenfa");
	map_skill("hand", "yingzhua-shou");
	map_skill("parry", "yingzhua-shou");
	prepare_skill("hand","yingzhua-shou");

	set("inquiry", ([
		"����»" : (: ask_yin :),
		"yin wulu" : (: ask_yin :),
		"��ӡ"  : (: ask_xunluo :),
	]));
	set("xl", 8);
	set("xl2", "yin2");
	create_family("����",37,"����");
	setup();
	carry_object("/d/mingjiao/obj/green-cloth")->wear();       
}

void init()
{
	::init();
        add_action("do_kill", "kill");
        add_action("do_kill", "tk");
        add_action("do_kill", "teamkill");
        add_action("do_kill", "hit");
}

void attempt_apprentice(object ob)
{        
        object me  = this_object();
        mapping fam = ob->query("family");
        mapping my_fam = me->query("family");
        if(!fam){
                command("hmm");
                command("say "+RANK_D->query_respect(ob)+"������ȥ��������ֵ�ѧ������������ɡ�"); 
                return;
        }
        if ( fam && (fam["family_name"] == "�䵱" || fam["family_name"] == "������"
            || fam["family_name"] == "������" || fam["family_name"] == "ؤ��"
            || fam["family_name"] == "������" || fam["family_name"] == "��ɽ��")){
                command("say ���������������ɣ�����������ʲ��");
                return;
        }
        if(fam["master_name"] == "���޼�"){
                command("haha");
                command("say "+RANK_D->query_respect(ob)+"���ǽ����״����ӣ�"+RANK_D->query_self(me)+"����������Ϊͽ��"); 
                return;
        }
        if (fam["generation"] <= my_fam["generation"]){
                command("shake");
                command("say "+RANK_D->query_respect(ob)+"������ʦ��"+RANK_D->query_respect(me)+"����������Ϊͽ��");
                return;
        }        
        if ((int)ob->query_skill("shenghuo-shengong", 1) < 50) {
                command("say Ҫѧ��Ϊ������书�������и�����ڹ���Ϊ��"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ����ʥ�����϶��µ㹦��");
                return;
        }     
        command("look " + ob->query("id"));
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
        command("recruit " + ob->query("id"));
        ob->set("title","������΢������������");
}


string ask_yin()
{
	object me, ob, where;
	me=this_player();
	ob = find_living("yin wulu");
	if (!ob) return "�����������������棬������»�����˸�ɱ�ˡ�\n";
	where = environment(ob);
	if (!where) return "����»����Ѳ��ȥ�ˣ���Ҳ��֪�������������\n";
		return "�ţ�����»������"+where->query("short")+CYN"һ��Ѳ�ߡ�"NOR;
}

int accept_object(object who, object ob,object me)
{
	me=this_object();
	if ( me->query("family/family_name") != "����"||ob->query("name")!="������"){
		command("? "+who->query("id"));
		command("say ����Ҷ�����ʲô��ͼ����");
		return 0;
	}
	if(!who->query_temp("shouwei")){
		command("say ���������ģ�û�õ���������������������");
		return 0;
	}
	if(ob->query("name")=="������"){
		command("say �ðɣ����Ȼ�������飬���������������һ�������ɡ�");
		who->apply_condition("mj_shouwei",random(4)+7);
		who->set_temp("shouweied",1);
		return 1;
	}
	return 1;
}

int do_kill(string arg)
{
	object ob,ob2; 
        object me = this_player();
        ob2 = this_object();

        if (!arg) return 0;
        ob = present(arg, environment(me));
        if (ob == this_object() || ob == me) return 0;
        if (!ob || !ob->is_character()) return 0;

        
        if (userp(ob) && ob->query("family/family_name") == "����") {
                if (me->query("family/family_name") == "����") { 
			message_vision(ob2->name()+"��$N�ȵ�����Ϊ���̵��ӣ���Ȼɱ�Լ���ͬ�ţ��������㣡\n", me);
		}
		else {
			message_vision(ob2->name()+"��$N�ȵ����󵨿�ͽ����Ȼ����������Ұ��\n", me);
			kill_ob(me);
		}
		me->set("vendetta/����", 1);
		return 1;
	}
        return 0;
}

#include "xunluo.h";
