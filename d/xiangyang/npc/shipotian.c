//shipotianc

inherit NPC;
#include <ansi.h>
int ask_taixuan();


void greeting(object me);

void create()
{
        set_name("ʯ����", ({ "shi potian", "shi", "potian" }) );
        set("gender", "����" );
        set("nickname",HIC"������"NOR);
        set("age", 16);
        set("long",
"һ���������ݵ��������ӡ�\n"
"���˽��������֣���Ҳ�����⡣\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 25);
        set("shen_type", 1);
  set("no_get", 1);
  set("no_bark", 1);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("hand", 200);
        set_skill("cuff",200); 
        
        set_skill("taixuan-gong",200);
        map_skill("force","taixuan-gong");
        map_skill("hand","taixuan-gong");
        map_skill("dodge","taixuan-gong");
        
        map_skill("parry","taixuan-gong");
    prepare_skill("hand", "taixuan-gong");
        set("combat_exp", 1000000);
        set("max_qi", 30000);
        set("max_jing", 3000);
        set("max_neili", 5000);
        set("eff_jingli",3000);
        set("qi",30000);
        set("jing",3000);
        set("jingli",3000);
        set("neili", 5000);
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       (: exert_function, "taixuan" :),
       (: perform_action, "hand.po" :),
       (: perform_action, "hand.xuan" :),
     }));

  set("inquiry", ([
    "̫����": (: ask_taixuan :),
    "������" : "�Ǻǣ������ҵ���š�",
    "����" : "�Ǻǣ������ҽ����ֳ���",
    "����" : "�Ǻǣ������ҽ����ֳ���",
    "л�̿�" : "���ϲ��������Ҽ����ܺ����С���ˡ�",
    
        ]));
        setup();
        
        carry_object("/clone/armor/cloth.c")->wear();
} 

void init()
{
  object me;
        ::init();
  if (interactive(me = this_player()) ) {
           me->start_busy(1);
       call_out("greeting", 2, me);
  }       
}

void greeting(object me)
{
                int i,p;
  if(!me) return;

        if(me->query_condition("killer"))
        {
          command("fear "+me->query("id"));
    command("say ����ɱ�˷����ǻ��ˣ�");
   
          return;
        }

  

}


int ask_taixuan() 
{
        object me = this_player();
        object ob = this_object();
   
if(me->query("taixuan_pass"))
  {
          command("disapp "+me->query("id"));
          command("say ������Ѿ�ѧ��̫�����˰ɣ�");
          return 1;
  } 
    


 //�书ѧϰ֮����Ҫ���һСʱ��������Ҫ���10K
        if(me->query("taixuan/ask"+"time") && time()-me->query("taixuan/ask"+"time")<3600)
        {
          command("shake "+me->query("id"));
          command("say �����ͱ����ˣ��ʶ����ۡ�");
          command("say ���˵Ҫ��һСʱ�Ժ󣬻�Ҫ��10K����Ŷ��");
          return 1;
  }
   if(me->query("taixuan/ask"+"combat_exp") && me->query("combat_exp")-me->query("taixuan/ask"+"combat_exp")<10000)
        {
          command("look "+me->query("id"));
          command("say ���㵱ǰ�ľ�����»����������򣬻���ץ��ȥ����ȥ�ɡ�");
command("say ���˵Ҫ��һСʱ�Ժ󣬻�Ҫ��10K����Ŷ��");
          return 1;
  }



if  (me->query_temp("taixuan/1"))
{
command("say �㲻���Ѿ�ȥ��ô?");
return 1;
}


if(me->query("pur") > 27)
    {
   
    message_vision(HIC"\n$n΢Ц�Ŷ�$N˵���������Ҫ��ϸ���ˡ�,˵�ն���$N�������Ｘ�䡣\n"NOR,me,ob); 
    me->set("taixuan/ask"+"time",time());
me->set("taixuan/ask",me->query("combat_exp"));
    
    tell_object(me,YEL"��ƴ����������䣬�·�ֻ�������͵�ʲô��.........\n"NOR);
    me->start_busy(2);
me->set_temp("taixuan/1",1);
    me->set_temp("taixuan/ask",1);
          return 1;
          }
          else
         {  
          
         command("say ���������ʲô?");
    return 1;
  }


}


