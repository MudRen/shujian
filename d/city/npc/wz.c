inherit NPC;
#include <ansi.h>

int ask_bagua();
int ask_liwu();
int ask_quanfa();
int ask_jiangli();


void create()
{
        set_name("��ʦ",({  "wizard", "wushi" }) );
        set("gender", "����" );
        set("age", 30);
        set("long", "����һ�������ٻ���������ʦ��ż��Э�����������£��󲿷ֵ�ʱ�䶼���������¡�\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("shen_type", 1);
        set("combat_exp", 100);
        set("attitude", "peaceful");
        setup();

        set("inquiry", ([
              "��������":   (: ask_liwu    :),
     //         "���Ű���":   (: ask_bagua   :),
     //         "�����书":   (: ask_quanfa  :),
                "���ֽ���":   (: ask_jiangli :),
                "���ר��":   (: ask_jiangli :),
            ]) );

        carry_object("/clone/misc/cloth")->wear();
}


int ask_bagua()
{      
       mapping myfam;    
       object me = this_player();
       myfam = (mapping)me->query("family");

       if(!myfam || myfam["family_name"] != "�һ���")
        {   
           if( !me->query_skill("qimen-bagua") || me->query_skill("qimen-bagua",1) < 50 )         
             { 
               command("say �ðɣ��ҿ��Խ���һ�����Ű��Ե�ѧ�ʡ�");
               me->set_skill("qimen-bagua", 52);
               return 1;
              }
           else {
                command("say ���Ѿ������Ե��ˣ��ҿɽ̲�����ʲô������");  
                 return 1; 
                  }
         }
         else 
         {    command("kick "+me->query("id"));
              command("say �㲻ȥ����ʦ���ú�ѧϰ����Ͷ��ȡ�ɰ���");
               return 1; }

}


int ask_quanfa()
{      
       
    object me = this_player(); 
   if( me->query("askwiz_cuff") ) 
       {
          command("say �Ҳ����Ѿ��̹����ˣ�");
          return 1;
       }


   if( me->query("combat_exp") < 150000  ) 
       {
          command("say ���ʵս���鲻�㣬����ץ��ʱ��ȥ�����ɡ�");
          return 1;
       }
   if( me->query("combat_exp") > 150000  ) 
       {
          command("say ���ʵս���鲻�㣬����ץ��ʱ��ȥ�����ɡ�");
          return 1;
       }

           
   me->set_skill("cuff", 1);
   me->set_skill("yeqiu-quan", 1);

     command("wink");
     command("fullskills "+me->query("id"));

     command("say �����У����ף��ҿ��Ը���һ����书�ϵ�ָ�㣬����ֻ��һ�λ���Ŷ��");
     me->set("askwiz_cuff",1);
 
     tell_object(me, HIG"��õ�����ʦ�İ������书���г�����\n"NOR);
    return 1;
        
}

int ask_liwu()
{
  
    object me = this_player(); 
   if( me->query("start_liwu") ) 
       {
          command("say �㲻���Ѿ�����ˣ�");
          return 1;
       }


   if( me->query("combat_exp") < 1000000  ) 
       {
          command("say ���ʵս���鲻�㣬����ץ��ʱ��ȥ�����ɡ�");
          return 1;
       }

   if( me->query("combat_exp") >= 1700000  ) 
       {
          command("say ��Ĺ����Ѿ��ܲ����ˣ������Լ��ڷ������ɡ�");
          return 1;
       }


     command("wink");
     command("fullskills "+me->query("id"));
     command("say ����ʵս�������ڵ�1M�ˣ��治����ѽ��");

     command("say ��л����֧�֣�ϣ������Ŀ��ģ���ĳ��ã�");
     me->set("start_liwu",1);

     me->add("SJ_Credit",500);
     me->add("balance", 1000000);


     tell_object(me, HIG"��õ��������ף�������"+ HIR + chinese_number(500) + CYN +"����"+HIG+"ͨ��"+CYN+"����\n"NOR);
     tell_object(me, HIG"��õ��������ף������� " + MONEY_D->money_str(1000000) + "��\n"NOR);


     CHANNEL_D->do_channel(this_object(), "rumor", HIC"��˵" + me->name(1) + "�ӻ���ҵ���ʦ�������һ�ݷ������\n"NOR);
    return 1;
}

int ask_jiangli()
{
  
    object me = this_player(); 

   if(!me->query("buyvip"))  {
          command("consider");
          return 1;
                             }

   if( me->query("combat_exp") < 5000000  ) 
       {
          command("say ���ʵս���鲻��5M������ץ��ʱ��ȥ�����ɡ�");
          return 1;
       }

   if( me->query("combat_exp") >= 75000000  ) 
       {
          command("say ��Ĺ����Ѿ��ܲ����ˣ������Լ��ڷ������ɡ�");
          return 1;
       }
   if( me->query("5m_jiangli") ) 
       {
          command("say �㲻���Ѿ�����ˣ�");
          return 1;
       }
       
       
     command("fullskills "+me->query("id"));
     command("ah");
     command("say ��ϲ��������������ֵ����У�");
     command("say ��������Ϊ�齣������ҵĶ��ؽ�����лл������������֧�ֺ�������");
     me->set("5m_jiangli",1);
     me->add("SJ_Credit",2000);
     me->add("balance", 20000000);

     me->set("last_full",1);

     me->add("relife/gifts/now",  2);  
     me->add("relife/gifts/total",  2);  
     me->add("imbue_reward",10);


     tell_object(me, HIC"��õ��������ף�������"+ HIR + chinese_number(2000) + HIC +"����"+HIG+"�齣ͨ��"+HIC+"���� " + MONEY_D->money_str(20000000) + "��\n"NOR);
     tell_object(me, HBBLU"��õ��������ף����������������ɷ���Ĳ����츳��������ʹ��addgiftָ����䣡\n"NOR);  
     tell_object(me, HBBLU"����ʮ�ζ���Ĵ�����ᣡ\n"NOR);   
     me->add("ggs/left_time",1080000);


    tell_object(me, HBBLU"�츳ϵͳ��ʼ��Ч������һ�ε�½��ʼ���㽫��ö���Ĺ���������ʵս�н�����������Ч����\n"NOR);  
 
     CHANNEL_D->do_channel(this_object(), "rumor", HIC"��˵" + me->name(1) + "�ӻ���ҵ���ʦ�������һ�ݹ��ר���"HIR"���ֽ���"HIC"���\n"NOR);
     return 1;     

}

