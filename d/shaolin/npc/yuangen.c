inherit NPC;
#include <ansi.h>

void create()
{
       set_name("Ե������", ({ "yuangen", "heshang" }) );
       set("gender", "����" );
       set("age", 50);
       set("long",
               "���������²˵ع��£�������ü���ۣ�\n");
       set("combat_exp", 10000);
       set("attitude", "friendly");
              set("inquiry", ([
             "�ֲ�" : "�����ֲ˶��������ӵģ���ĦԺ����Ҳ����ˣ�\n",
              
       ]) );
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
}
void greeting(object ob)
{
       if( !ob || environment(ob) != environment() ) return;
         
       if(ob->query_temp("job_name")!="�˵��ֲ�") return; 
        if(!(ob->query_temp("job_name")!="�˵��ֲ�"))   
       {
        command("stare "+ob->query("id"));
       command("say " + RANK_D->query_respect(ob)
                               + "��������⽽��"HIR"(jiao ��)"NOR"�ɡ�\n");
            }
}
