// due.c

inherit NPC;
inherit F_MASTER;
#include "bai-du.h"
string ask_me();

void create()
{
        object ob;
        set_name("�ɶ�", ({ "du e", "du", "e" }) );
        set("title", "���ֳ���");
        set("gender", "����");
        set("class", "bonze");
        set("age", 90);
        set("long", "����һ��������ݣ��ݹ��㶡����ɮ������ɫ�ݻƣ���ͬһ�ο�ľ��\n");
        set("attitude", "peaceful");
        set("combat_exp",2200000);
        set("shen", 50000);
        set("str", 30);
        set("int", 25);
        set("dex", 28);
        set("con", 28);
        set("qi", 6000);
        set("max_qi",6000);
        set("max_jing", 3000);
        set("eff_jingli", 2500);
        set("neili",6000);
        set("max_neili",6000);
        set("jiali", 70);
        set("no_get", 1);
        set("unique", 1);

        create_family("������", 35, "����");
        assign_apprentice("����", 0);
        set_skill("force", 180);
        set_skill("whip", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("buddhism", 180);
        set_skill("literate", 150);
        set_skill("yijin-jing", 180);
        set_skill("riyue-bian", 180);
        set_skill("shaolin-shenfa", 180);
        set_skill("hand",180);
        set_skill("fumoquan-zhen",180);
        set_skill("leg",180);
        set_skill("blade", 180);
        set_skill("xiuluo-dao", 180);
        set_skill("qianye-shou",180);
        set_skill("ruying-suixingtui",180);
        map_skill("force", "yijin-jing");
        map_skill("blade", "xiuluo-dao");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "xiuluo-dao");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("hand","qianye-shou");
        map_skill("leg","ruying-suixingtui");
        prepare_skill("hand","qianye-shou");
        prepare_skill("leg","ruying-suixingtui");
        set("inquiry", ([
                "��ħ����"     : (: ask_me :),
        ]));
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "whip.chanrao" :),
                (: perform_action, "whip.fumoquan" :),
                (: perform_action, "hand.qianshou" :),
                (: perform_action, "leg.ruying" :),
        })); 
        setup();
        if (clonep()) {
                ob=unew(BINGQI_D("whip/heisuo"));
                if (!ob) ob = unew(BINGQI_D("changbian"));
                ob->move(this_object());
                ob->wield();
                carry_object("/d/shaolin/obj/du-cloth")->wear();
        }       
}

void init()
{
        int i, j;
        object me, ob;
        mapping fam;
        me = this_player();
        ob = this_object();
        ::init();
        if(interactive(me)){
                if (mapp(fam = me->query("family")) && fam["family_name"] == "������" 
                && fam["generation"] <= 36 ) {
                        me->set_temp("fighter", 1);
                        return;
		}
                if (mapp(fam = me->query("family")) && fam["family_name"] == "������" 
                && fam["generation"] > 36               
                && me->query("qi") < 50 ) {
                        me->move("/d/shaolin/qyping");
                        me->unconcious();
                        return;
		}
                if(base_name(environment(ob))!="/d/shaolin/fumoquan") return;
                command("say �����ӷ�");
                i = me->query("combat_exp");
                j = me->query("potential");
                COMBAT_D->do_attack(ob, me, query_temp("weapon"), 2);
                COMBAT_D->do_attack(ob, me, query_temp("weapon"), 2);
                me->set("combat_exp", i);
                me->set("potential", j);
                me->set_temp("fighter", 1);
                remove_call_out("halt");
                call_out("halt", 0, me);
                return;
        }
        return;
}

void halt(object me)
{
	if(me->is_ghost()) return;
	if(!living(me) && environment(me) == environment()){
		message_vision("$N���ɶ��ó���һ���ӳ��˽�շ�ħȦ��\n", me);
		me->move("/d/shaolin/qyping");  
		message_vision("$N���˴Խ�շ�ħȦ�����˳�����\n", me);
	}
	else command("say �ðɣ����ס�֣� ����һ���ʲô��Ҫ˵��");
}

string ask_me()
{
        object whip;
        object ob,me;
        me = this_player();
        
	if ( !this_player()->query_temp("fighter") 
	 ||  this_player()->query("combat_exp") < 5000 ){
		command("say ���󱲣����δ�ɣ�����͵���շ�ħȦ�������������������㣡");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
		return 0;
        }

        if ( present("huangjin nao", this_player()) || present("fumo nao", this_player()))
                return RANK_D->query_respect(this_player())+ "����ֻ��һ�ԣ����Ҿ��������ϣ�����̰�����У�";

        if ( present("huangjin nao", environment()) || present("fumo nao", environment()))
                return RANK_D->query_respect(this_player()) + 
                "����ֻ��һ�ԣ����Ҿ�����������ȡ�ߣ�����̰�����У�";

        if(present("zhanyao nao", environment()) || present("zhanyao nao",this_player()))
                return RANK_D->query_respect(this_player())+ "������ն�����󣬾Ͳ������÷�ħ����ĪҪ̰�����У�";

        if ( present("jingang zhao", this_player()) || present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player())+ "ȡ�˽���֣��Ͳ������ûƽ���ĪҪ̰�����У�";

        if(me->query_temp("fmnao")) return "�ղŷ�ħ�����Ǹո�����"; 

	if( clonep()){
		ob= unew(BINGQI_D("blade/jinnao"));
		if(ob){
			destruct(ob);
			ob=unew(BINGQI_D("blade/jinnao1"));
		}
		if(ob) ob->move(this_object());
	}
	if ( present("fumo nao", this_object())){
		message_vision("\n�ɶ�Цһ�������ͷ�������еķ�ħ�����ò����á�\n\n", this_player());
		command("give fumo nao to "+this_player()->query("id")); 
		me->add_busy(2);
		me->set_temp("fmnao",1);
		whip = unew(BINGQI_D("whip/heisuo")); 
		if(clonep(whip)){
			whip->move(this_object());
			command("wield bian"); 
		}    
		else {
			if (!(whip = present("changbian", this_object()))) 
				whip = unew(BINGQI_D("changbian")); 
			whip->move(this_object());
			command("wield bian"); 
		}
		return "���Ȼ�ܴ�����շ�ħȦ������Ȼ�ǵ��������еķǷ������ֻ�����ʷ������ˣ�";
	}
	return "��Ǹ���������ˣ���ħ�����Ѿ�����ȡ���ˡ�";
}
