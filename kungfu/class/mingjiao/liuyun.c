// liuyun.c ����ʹ
// Modify By River@sj 99.06
#include <ansi.h>
inherit NPC;
int p();
void create()
{
        object ob;
        set_name("����ʹ", ({ "liuyun shi", "shi", "liuyun"}) );
        set("title", "���̲�˹��ʹ");
        set("gender", "����");
        set("attitude", "friendly");
        set("age",49);
        set("long", "����ĸߴ���ױ��ۡ�\n");
        set("rank_info/respect","ʹ��");
        set("str", 25);
        set("int", 22);
        set("con", 25);
        set("dex", 26);
        set("per", 20);
        set("unique", 1);
        set("shen_type",0);
        set("combat_exp", 800000);
        set_skill("dagger",130);//change blade to dagger by caiji
        set_skill("force",130);
        set_skill("parry",130);
        set_skill("cuff",120);
        set_skill("literate",100);
        set_skill("dodge",120);
        set_skill("piaoyi-shenfa",120);
        set_skill("shenghuo-shengong",130);
        set_skill("shenghuo-lingfa",130);
        map_skill("force","shenghuo-shengong");
        map_skill("dodge","piaoyi-shenfa");
        map_skill("dagger","shenghuo-lingfa");//change blade to dagger by caiji
        map_skill("cuff","shenghuo-lingfa");
        map_skill("parry","shenghuo-lingfa");
        prepare_skill("cuff","shenghuo-lingfa");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({ (: p :) }));
        set("max_qi",2700);
        set("max_jing",1800);
        set("neili",3000);
        set("max_neili",3000);
        set("jiali",50);
        set("eff_jingli",1700);     
        setup();
        if (clonep()) {
                ob = unew(BINGQI_D("shenghuo-ling"));
                if (!ob) ob = unew(BINGQI_D("tieling"));
                ob->move(this_object());
                ob->wield();        
                carry_object(ARMOR_D("changpao"))->wear();
        }     
}

void kill_ob(object me)
{     
        object ob;
        if(!this_object()->is_killing(me->query("id"))){  
          command("grin");     
          ::kill_ob(me);
          if(objectp(ob = present("miaofeng shi", environment(this_object())))
           && !ob->is_killing(me->query("id"))){
             message_vision(HIY"��Ц����$n���λζ���Խ������ʹվ��$N��ߣ���$N�����м䣡\n", me, ob);
             if(!ob->is_killing(me->query("id"))) ob->kill_ob(me); 
          }
          if(objectp(ob = present("huiyue shi", environment(this_object())))
           && !ob->is_killing(me->query("id"))){
             message_vision(HIY"��Ц����$n���λζ���Խ������ʹվ��$N��ߣ���$N�����м䣡\n", me, ob);
             if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);  
          }  
        }
        ::kill_ob(me);
}

int p()
{          
        if(this_object()->query_temp("yinfeng")){
           command("yun yinfeng");
           return 1;
        }
        else if(random(5) >=3){
           command("yun tougu");
           return 1;
        }
        else return 1;
}

void init()
{
        object ob;
        ::init();        
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "����")
           command("say ��ʥ������������٣�"+ob->name()+"�㻹���¹�");         
}
