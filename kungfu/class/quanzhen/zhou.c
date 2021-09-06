// zhou.c �ܲ�ͨ

#include <ansi.h>
inherit NPC;
// inherit F_MASTER;  ������ͽ
int ask_jieyi();
int ask_xlv();

void create()
{
        set_name("�ܲ�ͨ", ({"zhou botong", "zhou"}));
        set("gender", "����");
        set("age", 62);
        set("class", "taoist");
        set("nickname",HIY "����ͯ" NOR);
        set("long", "������ȥ��ü�԰ף�һ���õ�ģ����Ȼ������ȴ͸¶��һ�ɽ��\n");
        set("attitude", "peaceful");
        set("shen_type",1);
        set("str", 31);
        set("int", 36);
        set("con", 32);
        set("dex", 29);
  
        set("qi", 200000);
        set("max_qi", 200000);
        set("jing", 25000);
        set("max_jing", 25000);
        set("eff_jingli", 50000);
        set("jingli", 50000);
        set("neili", 500000);
        set("max_neili", 250000);
        set("jiali", 50);
        set("combat_exp", 10800000);

        set_skill("force", 450);
        set_skill("xiantian-gong", 450);
        set_skill("sword", 450);
        set_skill("quanzhen-jianfa",450);
        set_skill("dodge", 450);
        set_skill("jinyan-gong", 450);
        set_skill("parry", 450);
        set_skill("kongming-quan", 450);
        set_skill("strike", 450);
        set_skill("haotian-zhang", 450);
        set_skill("dafumo-quan", 400);
        set_skill("jiuyin-zhengong", 400);
        set_skill("jiuyin-shenfa", 400);
        set_skill("jiuyin-shenzhua", 450);
        set_skill("daode-jing", 450);
        set_skill("claw", 450);
        set_skill("cuff", 450);
        set_skill("literate", 200);
        set_skill("taoism", 200);
        set_skill("tiangang-beidouzhen", 200);
        set("double_attack",1);
        set("quest/jiebai/pass",1);

        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "kongming-quan");
        map_skill("strike", "haotian-zhang");
        map_skill("cuff", "kongming-quan");
        prepare_skill("cuff", "kongming-quan");
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.shuangjue" :),
                (: exert_function, "yiyang" :),
                (: exert_function, "wuqi" :),

        }));

        create_family("ȫ���", 1, "�ƽ�");
        set("title", "ȫ�����������ʦ��");

        set("book_count",1);
        set("inquiry", ([
                "ȫ���" :  "��ȫ��������µ����������ڡ�\n",
                "�����澭" : "�ٺٺٺ�...",
                "�λ�ү" : "��... �λ�ү���˼��ǻ�ү���Ҳ���ʶ��",
                "����"   : "�㣬��˵ɶ��",
                "����"   : "��...��...�ţ�",
//                "���": (: ask_jieyi :),
                "С��Ů": (: ask_xlv :),

        ]));

        setup();

        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}
/*

void attempt_apprentice(object ob)
{
      if(ob->query_skill("xiantian-gong",1) < 200 ||
         ob->query_skill("taoism",1) < 200 ||
         ob->query("shen")<1000000){
        command("say ����书����ѧ�ķ��������������������ٻ�ȥ�����ɡ�");
        return;
        }
        if(ob->query("int") >=26 ||
         ob->query("pur",1) < 26 ){
command("shake");        
command("say ���ĵع�ĺܣ�����׼���ʲô�����أ��ҿɲ����ա�");
        return;
        }



     command("say �������ʲ����Ҿ����������ͽ���ˣ����Ժ�Ҫ�������������ޡ�");        
     command("say �ðɣ�ƶ�����������ˡ�");
     command("recruit " + ob->query("id"));
     ob->set("title", HIC"����ͯ�ܲ�ͨ�״�����"NOR);
     ob->set("class","taoism");
}
*/
int ask_jieyi()
{
	object ob=this_player();
	/*
	if (!ob->query("family/family_name")  == "ȫ���") {
		command("draw " + ob->query("id"));
		command("say ����˭��");
	}
*/
	if (ob->query("quest/jiebai/pass")) {
		command("? " + ob->query("id"));
		command("say ���ǲ����Ѿ���ݹ�����");
		return 1;
	}

	if(ob->query("quest/jiebai/time") && time()-ob->query("quest/jiebai/time")<86400)
	{
	  command("shake "+ob->query("id"));
	  command("say �������Ѿ��ʹ��ˣ�������˵��");
	  return 1;
  }
	if(ob->query("quest/jiebai/combat_exp") && ob->query("combat_exp")-ob->query("quest/jiebai/combat_exp")<100000)
	{
	  command("look "+ob->query("id"));
	  command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
	  return 1;
  }


	if ( ob->query("int") > 25) {
		command("shake");
		command("say ������˹��龫������׼����ʲô�����ء�");
		return 1;
	}
	if ( ob->query("shen") <= -1) {
		command("shake");
		command("say ����Ȼ������㣬��ʦ��̻岻����������а֮������Ҫ����ġ�");
		return 1;
	}
	if ( ob->query("combat_exp") < 1000000) {
		command("shake "+ ob->query("id"));
		command("say ��λ"+RANK_D->query_respect(ob)+"�������ʵ��̫����ˣ��ҿ�û��Ȥ�����ݡ�");
		return 1;
	}
	if (random(ob->query("kar")) < 18 || random(ob->query_int(1)) < 25){
		command("shake");
		command("say ������û�пգ�Ҫ�������������棿");
		ob->add("quest/jiebai/fail", 1);
		ob->set("quest/jiebai/time",time());
    ob->set("quest/jiebai/combat_exp",ob->query("combat_exp"));
		log_file("quest/jiebai",
			sprintf("%-18s�����ܲ�ͨ��ݣ�ʧ��%s�Ρ�\n",
				ob->name(1)+"("+capitalize(getuid(ob))+")",
				chinese_number(ob->query("quest/jiebai/fail")) 
			), ob
		);
		return 1;
	}

	command("nod " + ob->query("id"));
	if (ob->query("gender") == "����") {
		command("say �ðɣ����Ҿͽ��Ϊ�ֵܰɡ�");
	}
	else if (ob->query("gender") == "Ů��") {
		if (ob->query("age") > 48)
			command("say �ðɣ����Ҿͽ��Ϊ��ܰɡ�");
		else
			command("say �ðɣ����Ҿͽ��Ϊ���ðɡ�");
	}
	message_vision("�ܲ�ͨ��$N�����������˵����������ͯ�ܲ�ͨ��������" + ob->name(1) +"���������պ��и��������ѹ�����\n"+
			"����Υ�����ģ������书ȫʧ����С��СèҲ�򲻹�����\n", ob);
	log_file("quest/jiebai",
		sprintf("%-18sʧ��%s�κ󣬳ɹ����ܲ�ͨ��ݣ�����%d����%d��\n",
			ob->name(1)+"("+capitalize(getuid(ob))+")",
			chinese_number(ob->query("quest/jiebai/fail")), 
			ob->query("kar"), 
			ob->query_int(1)
		), ob
	);
	ob->set("quest/jiebai/pass", 1);
	ob->set_skill("kongming-quan",15);
	return 1;
}



int accept_object(object me, object ob)
 {
    if( ob->query("id") == "yufeng zhen" && me->query("family/family_name")=="��Ĺ��") {
       command("ah ");
       command("say һ�������������������ҵİɡ� ");
       command("say �����ұ����ַ����Ķ���ҧ�У������СС�Ľ���ⶾ�� ");
       me->set_temp("marks/yufengzhen",1);
             call_out("destructing", 1, ob); 
                return 1; 
            }
  
    else {
       command("hmm ");
       command("say �����������Ķ���������ʲô�ã� \n");

            return 0;
           }
    return 1;
 } 

int ask_xlv()
{
	object me=this_player();


	command("tsk ");
	command("say ��������������С�һ���˲��ã�����һ�����ɾ��¡�");
 
if( me->query_temp("marks/yufengzhen") && !me->query("gmhb") )
{
	message_vision(HIY"�ܲ�ͨһ��������С��Ů�����飬���ɵ�ü��ɫ�衣\n"+
			"�ܲ�ͨ���㽲��������С��Ů�����ַ����Ķ�֩������ɽ��֮�У�С��Ů\n"+
    	"ѧ�����һ�����һ��ȫ�潣һ����Ů����Ľ��ַ�����Ķ��ӣ�˵������֮����\n"+
    	"���ɵ������㵸����ĭ�Ľ���\n"+
    "�ܲ�ͨ�����㿴�˿���������Ȥ���ʵ�������֪����������û�н������Ź��򣿡�\n"NOR, me);
    me->set_temp("marks/askzhou",1);
    me->delete_temp("marks/yufengzhen");
}
	return 1;

}
