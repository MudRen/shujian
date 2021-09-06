// song.c ��Զ��

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

string* names = ({
        "/d/wudang/sanqingdian",
        "/d/wudang/xiaolu1",
});

string ask_me();

string ask_me1();

string ask_me2();

void create()
{
       set_name("��Զ��", ({ "song yuanqiao", "song" }));
       set("nickname", "�䵱����");
       set("long", 
               "������������Ĵ���ӡ��䵱����֮�׵���Զ�š�\n"
               "��һ���ɸɾ����Ļ�ɫ���ۡ�\n"
               "���������ʮ������ݳ���������⡣�񵭳�ͣ���Ĭ���ԡ�\n");
       set("gender", "����");
       set("unique", 1);
       set("age", 61);
       set("attitude", "peaceful");
       set("shen", 10000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       
       set("max_qi", 1500);
       set("max_jing", 1000);
       set("neili", 2000);
       set("max_neili", 2000);
       set("jiali", 50);
       set("combat_exp", 1000000);
//     set("score", 60000);
       set_skill("force", 130);
       set_skill("yinyun-ziqi", 130);
       set_skill("dodge", 130);
       set_skill("wudang-quan", 130);
       set_skill("tiyunzong", 130);
       set_skill("strike", 180);
       set_skill("zhenshan-mianzhang", 180);
       set_skill("parry", 130);
       set_skill("literate", 100);
       set_skill("xuanxu-daofa", 140);
       set_skill("wudang-quan", 140);
       map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "zhenshan-mianzhang");
       map_skill("parry", "zhenshan-mianzhang");
       prepare_skill("strike", "zhenshan-mianzhang");
       create_family("�䵱��", 2, "����");

       set("inquiry", ([
               "�ؼ�" : (: ask_me :),
                "��Ҫ" : (: ask_me1 :),
                "����" : (: ask_me2 :),
                "job" : (: ask_me2 :),
                "Ѳɽ" : (: ask_me2 :),
       ]));
       set("book_count1", 1);
       set("book_count2", 1);
       setup();
//     carry_object("/clone/weapon/changjian")->wield();
       carry_object("/d/wudang/obj/white-robe")->wear();

}
void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }       
     
}
void greeting(object ob)
{
        int e,p;
        p = 20+random(80);
        e = 20+random(80);
        if(ob->query_temp("wd/wd_job_lost2") )
       {
        command("faint "+ob->query("id"));
        command("say "+ob->name()+"���Ѿ����˰�����Ƕ����������ˣ�");
        ob->delete_temp("wd/wd_job_lost2");
       }
        if(ob->query_temp("wd/wd_job_lost") )
       {
        command("sigh "+ob->query("id"));
        command("say "+ob->name()+"����ô��ģ���Ȼ���Ƕ��������ˣ�");
        ob->delete_temp("wd/wd_job_lost");
        ob->apply_condition("job_busy",3+random(4) );
       }
        if(ob->query_temp("wd/wd_jobok") ){
        command("thumb "+ob->query("id"));
        command("say �ܺã�ף���������������ȥ��Ϣ��Ϣ�ɣ�");
        ob->add("combat_exp",e);
        ob->add("potential",p);
        ob->delete_temp("wd/wd_job");
        ob->delete_temp("wd/wd_jobok");
        if ( (int)ob->query("potential", 1) > (int)ob->query("max_pot", 1) )
        ob->set("potential" , ob->query("max_pot", 1) );
        tell_object(ob, GRN"
������"+CHINESE_D->chinese_number(e)+"�㾭�飬"+CHINESE_D->chinese_number(p)+"��Ǳ�ܣ�\n"NOR);
        write_file( "/log/wd_job",sprintf("%s %s(%s)Ϊ���䵱Ѳɽ��������%d�㾭�飬%d��Ǳ�ܡ�\n",
ctime(time())[4..19],ob->name(),ob->query("id"),e,p));
//        ob->apply_condition("job_busy",1+random(2) );
        }
        return;
}
void kill_ob(object me)
{
        //set("combat_exp", 750000);    
        //set("max_qi", 2500);
        //set("max_neili", 2000);
        //set("neili", 2000);
        //set("jiali", 100);
       set("chat_chance_combat", 20);
       set("chat_msg_combat", ({
               (: perform_action, "strike.bingdi" :),
               (: perform_action, "dodge.zong" :),
        }));
        ::kill_ob(me);       
} 

int accept_fight(object me)
{
        if((int)me->query("shen") < 1) {
           command("say ϰ��֮��Ӧ־�ڳ�����ƣ�"+RANK_D->query_respect(me)+"Ŀ¶��������Υ��ѧ֮����");
           return 0;
        }
        ::fight_ob(me);
         return 1;
}

void attempt_apprentice(object ob)
{
       if ((int)ob->query("shen") < 10000) {
               command("say ���䵱���������������ɣ��Ե���Ҫ���ϡ�");
               command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                       "�Ƿ����ò�����");
               return;
       }
       command("say �ðɣ�ƶ�����������ˡ�");
       command("recruit " + ob->query("id"));
}

string ask_me()
{
       mapping fam; 
       object ob;
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
               return RANK_D->query_respect(this_player()) + 
               "�뱾��������������֪�˻��Ӻ�̸��";
       if(query("book_count2") < 1)
         return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
       add("book_count2",-1);       
       ob = new(__DIR__"force_book");
       ob->move(this_player());
       return "�ðɣ��Ȿ��̫��ʮ��ʽ�����û�ȥ�ú����С�";
}

string ask_me1()
{
        mapping fam; 
        object ob,song;        
        song = this_object();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "�䵱��")
                return RANK_D->query_respect(this_player()) + 
                "�뱾��������������֪�˻��Ӻ�̸��";
        if (query("book_count1") < 1)
           return "�������ˣ�������Ҫ�Ѿ����ڴ˴��ˡ�";
        add("book_count1",-1);         
        ob = new(__DIR__"blade_book");
        ob->move(this_player());
        return "�Ȿ���н����ĵ���Ҫ�죬���ȥ�ú��о�һ�¡�";
}
string ask_me2()
{
        object me, ob;
        string objwhere;
        me=this_player();

        if (me->query_temp("wd/wd_job"))
           return "���ƺ���û������������ɣ�";
        if ((int)me->query("combat_exp") < 200000 )
           return "��ʵս���鲻�㣬����ȥ���������������ͭ���Ĺ����ɣ�";
        if(me->query_condition("job_busy"))
           return "������ʱ��û�й�������ȥ����";

        me->set_temp("wd/wd_job",1);
        command("nod "+me->query("id"));
        ob=new("/d/wudang/npc/attacker");
        ob->set_temp("target", me->query("id") );
        objwhere = names[random(sizeof(names))];
        ob->move(objwhere);
        return "��˵������"+objwhere->query("short")+CYN"�������ң�������ȥ����Ѳ��һȦ��";
}