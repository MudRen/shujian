//by daidai
#include <ansi.h>
//inherit NPC;
inherit FIGHTER;
#define QUESTJINSHE "quest/���߽���/"

void create()
{
	set_name("�·�ʩ", ({ "wen fangshi", "wen", "fangshi" }));
        set("gender", "����");
        set("title", "�¼�����");
        set("long", 
        "�������¼����ϵ������·�ʩ��\n"
        "һ�������ʮ�����ߣ���ͷ���Ѿ���ס�\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 25);
        set("shen_type", -1);
        set("unique", 1);

        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("blade", 300);
        set_skill("cuff",300); 
        set_skill("yijin-jing",300);
        set_skill("shaolin-shenfa",300);
        set_skill("wenjia-daofa",300);
        set_skill("wenjia-quan",300);
        set_skill("wuxing-zhen",200);
        
        map_skill("force","yijin-jing");
        map_skill("cuff","wenjia-quan");
        map_skill("blade","wenjia-daofa");
        map_skill("dodge","shaolin-shenfa");
        map_skill("parry","wenjia-quan");
        
      prepare_skill("cuff", "wenjia-quan");

  
        set("combat_exp", 2000000);
        set("max_qi", 30000);
        set("max_jing", 3000);
        set("max_neili", 5000);
        set("eff_jingli",3000);
        set("qi",30000);
        set("jing",3000);
        set("jingli",3000);
        set("neili", 5000);

       setup();  
        
     carry_object(ARMOR_D("cloth"))->wear();
    carry_object("/clone/weapon/blade1")->wield();

}
void init()
{
    object me, ob;  
    int i;    
    ::init();

    ob = this_object();
    if(!ob->query("kill_id")) return;
          me=find_player(ob->query("kill_id"));  
        if(!me) return;
          if(environment(me)!=environment(ob)) return;
    if(ob->query("setok")) return;
        ob->set("setok",1);                             
          ob->copy_state();     
        //�������ɸ���npc ��һЩ״̬
          i=me->query("max_pot");
          if(i<350) i=350;
          i=i-100;      
         ob->set_skills_level(i-random(100)+random(50));
          if(random(2)) ob->set("combat_exp",me->query("combat_exp"));
    else        ob->set("combat_exp",me->query("combat_exp")*2/3); 
          ob->set("max_neili",me->query("max_neili"));
        ob->set("max_jingli",me->query("max_jingli"));
        ob->set("max_qi",me->query("max_qi")*3/2);
        ob->set("max_jing",me->query("max_jing"));
                ob->set("neili",query("max_neili")*3/2);
                ob->set("jingli",query("max_jingli")*3/2);
                ob->set("eff_jingli",query("max_jingli")*3/2);
                ob->set("qi",query("max_qi"));
                ob->set("eff_qi",query("max_qi"));
                ob->set("jing",query("max_jing")*3/2);
                ob->set("eff_jing",query("max_jing")*3/2);
                ob->set_skill("wuxing-zhen",200);
                remove_call_out("zhen");
                call_out("zhen",1,ob);
                remove_call_out("dest");
                call_out("dest", 600,ob);
                remove_call_out("do_kill");
                call_out("do_kill",2, me);
}

void zhen(object ob) 
{
   if( !ob ) return;                   
   command("lineup with wen fangshi");
   command("lineup with wen fangda");
   command("lineup with wen fangwu");
   command("lineup with wen fangyi");
   command("lineup with wen fangshan");
   command("lineup form wuxing-zhen");   
   command("lineup with wen fangshi");
   command("lineup with wen fangda");
   command("lineup with wen fangwu");
   command("lineup with wen fangyi");
   command("lineup with wen fangshan");
   call_out("zhen",1,ob);
}
int do_kill(object me)
{
        object ob = this_object();
        if(!me) return 0;
        remove_call_out("checking");
        call_out("checking", 2, me, ob);
        ::do_kill(me);
}

//��飬quest���̲���������
int checking(object me, object ob)
{
        int ret =  ::checking(me,ob);
        if(!ret) return 0;
        remove_call_out("checking");
        call_out("checking", 1, me, ob);
  if(!living(me) && living(ob) && ob->query("jing")>0 && ob->query("jingli")>0 && ob->query("qi")>0  ){
                remove_call_out("checking");
                tell_room(environment(me), HIB"\n"+me->name()+"�ۿ����ǲ��У�ͻȻһ�ɾ���Ϯ����������һ�ٳ���һ����϶��"+me->name()+"˳�ƴ����¼ұ�ׯ��\n"NOR);
                me->move("/d/xiangyang/ncx3");
                tell_room(environment(me), HIB"\nһ����ӰͻȻ������������ϸ������ԭ����"+me->name()+"��ֻ��"+me->name()+"ͻȻһ�٣���Ȼ�赹�ڵء�\n"NOR);
                me->delete_tem(QUESTJINSHE+"start_kill");
                me->delete_temp(QUESTJINSHE+"kill");
                me->delete_temp(QUESTJINSHE+"kill_5wen");
                me->delete_temp(QUESTJINSHE+"have_kill");
                me->set("qi",100);                                                              
                me->set("jing",100);
                me->set("jingli",100);
        log_file("quest/FEIHU", sprintf("%s��¼��%s(%s)���߽���ʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
    tell_room(environment(ob), ob->name()+"����һ��������׷����\n");
                destruct(ob);
                return 1;
        }
 if( !me || me->is_ghost()||me->query("eff_qi")<me->query("max_qi")/15||me->query("qi")<me->query("max_qi")/20  || environment(me)!=environment(ob)){
                remove_call_out("checking");
                remove_call_out("do_lost");
                call_out("do_lost",0);
                return 1;
        }
   if(!me->is_fighting(ob)){remove_call_out("do_kill");  call_out("do_kill",1,me);}
}
void do_lost()
{
        object me,ob;
        ob = this_object();
        if(!ob) return;
        me=present(ob->query("kill_id"),environment(ob));
        if(!me) me = find_player(ob->query("kill_id"));
        if(me)
        {
                me->delete(QUESTJINSHE+"start_kill");

                me->delete_temp(QUESTJINSHE+"kill");
                me->delete_temp(QUESTJINSHE+"have_kill");
                me->delete_temp(QUESTJINSHE+"kill_5wen");

        log_file("quest/FEIHU", sprintf("%s��¼��%s(%s)���߽���ʧ�ܡ�����%d��\n", ob->name(1),me->name(1),me->query("id"), me->query("combat_exp")) );
        }
  tell_room(environment(ob), ob->name()+"����һ����������㱾�°�����\n");
        destruct(ob);
}

void dest(object ob)
{
  if(!ob) return;
  tell_room(environment(ob), HIR+"\n"+ob->name()+"����һ�����������������ǳ�~~~~~~~\n"NOR);
        destruct(ob);
}
void die()
{
        object me,ob=this_object();
        
        if(ob->query("kill_id") )
        {
                me=present(ob->query("kill_id"),environment(ob));
                if(!me) me = find_player(ob->query("kill_id"));
                if(!me) return 0;
      if(me->query_temp(QUESTJINSHE+"start_kill")) 
      { 
                if(!me->query_temp(QUESTJINSHE+"kill"))
                {
                  me->add_temp(QUESTJINSHE+"kill_5wen",1);
                  if(me->query_temp(QUESTJINSHE+"kill_5wen")==5)
                  {
                    me->set(QUESTJINSHE+"over",1);
                    me->set_temp(QUESTJINSHE+"have_kill",1);
                    me->delete_temp(QUESTJINSHE+"kill_5wen");
                  }
                }
            }
  }
        command("disapp");
    
        ::die();
}


