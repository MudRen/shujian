//dudajin.c�����׼ҵ���
//by hunthu 
#include <ansi.h>

inherit NPC;
string *names = ({"�˵��ֲ�","�������ȷ���","�෿",});


string ask_job();

void create()
{
       set_name("�����", ({ "du dajin","du","dajin" }));
       set("title", "�����");
       set("gender", "����");
       set("age", 45);
       set("str", 27);
       set("dex", 26);
       set("long", "������ò���ã���Ŀ��࣬һ����֪�����ú���\n");
       set("combat_exp", 500000);
       set("shen_type", 1);
       set("attitude", "friendly");
       set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),(: perform_action, "finger.wofo" :),
        }) );

       set_skill("force", 100);
       set_skill("finger", 120);
       set_skill("yizhi-chan", 120);
       set_skill("yijin-jing", 120);
       set_skill("shaolin-shenfa", 120);
       set_skill("dodge", 100);
       set_skill("parry", 100);
      map_skill("dodge", "shaolin-shenfa");
      map_skill("parry", "yizhi-chan");
      map_skill("force", "yijin-jing");
      map_skill("finger", "yizhi-chan");
      prepare_skill("finger","yizhi-chan");
     /*  set_temp("apply/attack", 100);
       set_temp("apply/defense", 100);
       set_temp("apply/armor", 100);
       set_temp("apply/damage", 100);*/


       set("qi", 2000);
       set("max_qi", 2000);
       set("neili", 2500); 
       set("max_neili", 2500);
       set("jiali", 150);
 set("inquiry", 
                ([
                       "����" : (: ask_job :),
                            "job" : (: ask_job :),
                    
                ]));

      create_family("������", 38, "����");
//     carry_object("/d/shaolin/obj/hui-cloth")->wear();
    setup();
}
void init()
{
        object ob;

        ::init();
       if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
//             add_action("do_task","task");
}
string ask_job()
{
        object me;
        object ob;
        string target;
        ob=this_player();
        me=this_object();
              target = names[random(sizeof(names))];
        if (ob->query_temp("job_name"))
                return ("�㲻���Ѿ����˹����𣿻�����ȥ����\n");
            if (ob->query("combat_exp")>=30000)
                     return ("���Ѿ����˻����ˣ�û��Ҫ������������ˡ�\n");
          if ((string)ob->query("class")!="bonze")
          return ("�׼ҵ��Ӳ����칤����");
          ob->set_temp("job_name",target);
       //ob->apply_condition("wuguan_job",random(3)+4);
        return "��ɮ�¾�Ҫ�ܳԿ����ͣ���ȥ"+ target+ "�ɡ�";
    }

int do_task(string arg)
{
       object ob,me;
       ob=this_player();
       me=this_object();
       if(!arg) return 0;
       if(arg!="ok") return notify_fail("������!\n");
       if(!ob->query_temp("job_name")) 
            return notify_fail("��û���㹤��������ô���������ˣ�\n");
      if(!(ob->query_temp("mark/��Ħ��")||ob->query_temp("mark/����")||ob->query_temp("mark/����")))
            return notify_fail("����͵�������ɻ��Ҫ����ȥ��! \n");
      if(arg=="ok"&&(ob->query_temp("mark/����")||ob->query_temp("mark/��Ħ��")||ob->query_temp("mark/����")))
       { 
         command("pat "+ob->query("id"));
         command("say �ã�"+RANK_D->query_respect(ob)+"�����³Կ࣬�����������޳�������\n");
         if (random((int)ob->query("kar",1))>10)
        {
         command("say �����Ҿ�ָ���㼸�ֻ����书�ɡ�\n");                
         switch (random(4))
        {
          case 0:
          tell_object(ob,"�������ϸ�ĸ��㽲������Ṧ�ľ��ϣ��������ǳ��\n");
          ob->improve_skill("dodge", me->query("int")*2);
          break;
          case 1:
          tell_object(ob,"�������ϸ�ĸ��㽲������мܵľ��ϣ��������ǳ��\n");
          ob->improve_skill("parry", me->query("int")*2);
          break;
          case 2:
          tell_object(ob,"�������ϸ�ĸ��㽲������ڹ��ľ��ϣ��������ǳ��\n");
          ob->improve_skill("force", me->query("int")*2);
          break;
          case 3:
          tell_object(ob,"�������ϸ�ĸ��㽲�����ָ���ľ��ϣ��������ǳ��\n");
          ob->improve_skill("finger", me->query("int")*2);
          break;
         } 
               }
                    ob->add("potential",(int)(ob->query_skill("buddhism",1)/5)+30);
                if(ob->query("potential") > ob->query("max_pot")) ob->set("potential", ob->query("max_pot"));
                  ob->add("combat_exp",(int)(ob->query_skill("buddhism",1)/5)+60);
             ob->delete_temp("job_name");
             ob->delete_temp("mark");
          return 1;
         }
       return 1;
    }          

void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
         
      if(ob->query_temp("job_name")) return; 
       if ((ob->query("combat_exp") < 30000)&&((string)ob->query("class")=="bonze")) {
       command("buddhi "+ob->query("id"));
       command("say ��λ" + RANK_D->query_respect(ob)
                               + "��Ϊ�����¸ɵ��ɣ���������Ҫ������"HIR"(ask du about job)"NOR"������\n");
       }
}                            