// chenglingsu
//modified by tangfeng@SJ 2004

inherit F_MASTER;
inherit NPC;
#include <ansi.h>

#define QUESTDIR3 "quest/ѩɽ�ɺ�/��ҩƪ/"

string ask_jindi();
int ask_jieyao();
int ask_yaofang();
int ask_qixinghaitang();
int ask_hufei();
void destroying(object obj);
void giveyaofang(object me);

void create()
{
       set_name("������", ({ "cheng lingsu", "cheng" }));
       set("nickname", "ҩʦ");
       set("long", 
               "������ҩʦ�����ء�\n"
               "����ѽ��ж�ʮ���꣬���Ǹ���ҩ��Ϊ��ͨ��\n");
        set("gender", "Ů��");
       set("age", 21);
       set("attitude", "friendly");
       set("shen", -3000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       
       set("max_qi", 200);
       set("max_jing", 100);
       set("neili", 1000);
       set("max_neili", 1000);
       set("jiali", 10);
       set("combat_exp", 80000);
       set("no_get",1);
       set("no_bark",1);
       set_skill("force", 60);
        set_skill("yinyun-ziqi", 60);
       set_skill("dodge", 60);
       set_skill("jinshe-zhangfa", 60);
       set_skill("tiyunzong", 60);
       set_skill("strike", 60);
       set_skill("jinshe-jianfa", 60);
       set_skill("parry", 60);
       set_skill("sword", 60);
       set_skill("poison", 160);
       set_skill("medicine", 160);
       set_skill("literate", 120);
        map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "jinshe-zhangfa");
       map_skill("parry", "jinshe-jianfa");
       map_skill("sword", "jinshe-jianfa");
       prepare_skill("strike", "jinshe-zhangfa");

       set("inquiry", ([           
                "�嶾��" : (: ask_jindi :),
                "��ҩ" : (: ask_jieyao :),
                "ҩ��" : (: ask_yaofang :),
                "����" : (: ask_jieyao :),
                "���Ǻ���" : (: ask_qixinghaitang :),
                "���" : (: ask_hufei :),
                "����" : (: ask_jindi :),
                "���˷�" : "������书��ǿ��������Σ������������������������\n",
                "��һ��" : "�ɶ�������һ����\n",
       ]));
       setup();
       carry_object("/clone/armor/cloth")->wear();
}
void init()
{        
     add_action("do_yes","yes");
     add_action("do_no","no");
}
string ask_jindi()
{
       object applicant;
       object ob;
       int exp;
       applicant=this_player();

        exp=(int)applicant->query("combat_exp",1); 
        if(exp<90000)
        return "�����㹦�򣬿������嶾�̵�ɽҲ�ϲ�ȥ���ȼ�����˵�ɣ�\n"; 
 
        if (  present("jiuxuebiyun dan", this_player()) )
        return "���Ѿ��������ˣ�Ϊ�λ�Ҫ����Ҫ����ҩ�������ƣ���Ҫ̫̰�ģ�\n";
       
        if( applicant->query("wudu_jiedu") ){
        ob = new(__DIR__"obj/jxdan1");
        ob->move(applicant);
        message_vision("$N���һ�ž�ѩ���Ƶ���\n",this_player());
 
        return "���ϴδ�Ӧ�ҵ����黹û������������Ҫ�� ������������ü��
�����˵��������������һ�ţ���Ҫ����ȥ�ɡ�\n";
        }
 
         applicant->set_temp("marks/��",1);
         return "�嶾�̵Ľ��������˸����滨��ݣ����д󲿷־��о޶������һ������
�����������У��ؽ��ж��������������ȥ�嶾�̣��������пŵ�ҩ�ɵ����䶾��������
��ȥ����Ѱ��ѩ�룬��Ը����ҩ�����㣬�㿼��һ�£��Ƿ��Ӧ(yes)���߲���Ӧ(no)�ҡ�\n";
        
        
}
int do_yes()
{
    
   object jxdan, me, ob;
   me = this_object();
   ob = this_player();

   if(!ob->query_temp("marks/��")) return 0;
        jxdan = new(__DIR__"obj/jxdan");
   ob->set("wudu_jiedu", 1);
   ob->delete_temp("marks/��");	
   jxdan->move(this_player());
   message_vision("$N���һ�ž�ѩ���Ƶ���\n",this_player());
   message_vision("$N����΢΢һЦ��˵����ף�����˳��������ϣ�������Զ����š�\n",me, this_object()); 
   return 1;
} 
int do_no()
{
   object me = this_player();
   if(!me->query_temp("marks/��")) return 0;
   message_vision("���������ε�һЦ��˵������Ȼ�㲻�ܴ�Ӧ�ҵ�Ҫ�󣬵�ҩ��Ȼ���ܸ��㡣\n",me);
   me->delete_temp("marks/��");	
   
   return 1;
}
int accept_object(object who, object ob,object me)
{
	 if(who->query_condition("killer"))
	 {
	   command("shake "+who->query("id"));
     command("say ��Ŀǰ���ٸ�ͨ��������θ���"+ob->name()+"��");
	   return 0;
	 }
	 if(ob->query("id")=="qixing haitang" )
   {
   	 command("ah "+(string)who->query("id"));
     if(who->query_temp(QUESTDIR3+"qixinghaitang") && who->query(QUESTDIR3+"start")&& ob->query("owner")==who->query("id"))
     {
     	command("nod "+(string)who->query("id"));
     	command("say ������������Ҫ�������ҩ������Ҫһ�ֶ����������������嶾�̣�һ����ɫ��ҩ����");
     	who->set_temp(QUESTDIR3+"jieyao2",1);
     	who->delete_temp(QUESTDIR3+"qixinghaitang");
     }
     else  command("thank "+(string)who->query("id"));
   }
   else if(ob->query("id")=="lanse yaohua")
   {
   	 command("ah "+(string)who->query("id"));
     if(who->query_temp(QUESTDIR3+"jieyao2") && who->query(QUESTDIR3+"start")&& ob->query("owner")==who->query("id"))
     {
     	command("nod "+(string)who->query("id"));
     	command("say ����������΢����һ�£������Ͼͺá�\n");
     	tell_object(who,HIC"�����ؿ�ʼ�����ҩ���ӳ����Ͽ���ֻҪҩ����ȫ���ƺ����Ǻܸ��ӡ�\n\n"NOR);
	    tell_room(environment(who),HIC"\n������ת�����ƺ���ʼ�����ҩ��\n"NOR, ({ who }));
     	who->set_temp(QUESTDIR3+"getjieyao",1);
     	who->delete_temp(QUESTDIR3+"jieyao2");
     	who->start_busy(4);
      remove_call_out("giveyaofang");
      call_out("giveyaofang",10, who);
     }
     else  command("thank "+(string)who->query("id"));
   }
   else if (ob->query("id") == "xue zhu" )
   {
   	 command("thank " + who->query("id"));
     command("say ���Ȼ�Զ����ţ��´���Ҫ��ȥ�嶾�������Ұɡ�\n");
     who->delete("wudu_jiedu");
   }
   else
   {
     command("? "+(string)who->query("id"));
   }
   call_out("destroying", 1, ob);        
   return 1;
}
void destroying(object obj)
{
        if(!userp(obj)) destruct(obj);
        return;
}
void giveyaofang(object me)
{
      object obj;
      if(!me) return;
 
      obj=new("/d/miaojiang/npc/obj/yaofang");
      if(!obj) return;
      if(!me->query_temp(QUESTDIR3+"getjieyao")) return;
	    if(environment(me)!=environment(this_object()))
 	    {
 	    	command("say ���أ��ѵ���Ҫ��ҩ�ˣ�");
       	me->delete_temp(QUESTDIR3+"getjieyao");
 	    	return;
 	    }
     	command("nod "+(string)me->query("id"));
     	command("say ���ż��˰ɡ�����ҩ���������ʹ�������Ǹ�ҩ¯������");
      obj->move(me);
      tell_object(me,HIC"�����ظ���һ��"+HBCYN"ҩ��"NOR+HIC"��\n"NOR);
            tell_room(environment(me),HIC"\n�����ؽ���"+me->query("name")+"һ��ֽ��\n"NOR, ({ me }));
  	  if(!present("qixing haitang",me))
  	  {
  		  obj=new("/d/miaojiang/npc/obj/qixinghaitang");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"���Ǻ���"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("lanse yaohua",me))
  	  {
  		  obj=new("/d/miaojiang/npc/obj/lanseyaohua");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"��ɫҩ��"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("ren shen",me))
  	  {
  		  obj=new("/clone/medicine/drug/renshen.c");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"�˲�"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("jinyin hua",me))
  	  {
  		  obj=new("/clone/medicine/drug/hua.c");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"������"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("zang honghua",me))
  	  {
  		  obj=new("/clone/medicine/drug/zanghonghua.c");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"�غ컨"NOR+HIC"��\n"NOR);
  	  }
      return;
}
int ask_yaofang() 
{
	object obj,me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("nod "+me->query("id"));
	  command("say ���Ǻ��ģ��ɳ�ν���µ�һ��ݣ�����綾�ޱȡ������ְ취���������Ҳ������֮�١�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")
      && me->query_temp(QUESTDIR3+"getjieyao"))
  {
  	  if(!present("qixing haitang",me))
  	  {
  		  obj=new("/d/miaojiang/npc/obj/qixinghaitang");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"���Ǻ���"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("lanse yaohua",me))
  	  {
  		  obj=new("/d/miaojiang/npc/obj/lanseyaohua");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"��ɫҩ��"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("ren shen",me))
  	  {
  		  obj=new("/clone/medicine/drug/renshen.c");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"�˲�"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("jinyin hua",me))
  	  {
  		  obj=new("/clone/medicine/drug/hua.c");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"������"NOR+HIC"��\n"NOR);
  	  }
  	  if(!present("zang honghua",me))
  	  {
  		  obj=new("/clone/medicine/drug/zanghonghua.c");
  		  obj->set("no_give",1);
  		  obj->set("no_sell",1);
  		  obj->set("no_drop",1);
  		  obj->move(me);
        tell_object(me,HIC"�����ظ���һ��"+HBCYN"�غ컨"NOR+HIC"��\n"NOR);
  	  }
  	  
  	if(!present("yao fang",me))
  	{
  		obj=new("/d/miaojiang/npc/obj/yaofang");
  		obj->move(me);
      tell_object(me,HIC"�����ظ���һ��"+HBCYN"ҩ��"NOR+HIC"��\n"NOR);
     	command("say ��Ҫ�ٶ��ˡ�");
  	}
  	else
  	{
      command("sigh "+me->query("id"));
	    command("say ���Ǻ��ģ��ɳ�ν���µ�һ��ݣ�����綾�ޱȡ������ְ취���������Ҳ������֮�١�");
	  }
	  return 1;
  } 
  command("say ���Ǻ��ģ��ɳ�ν���µ�һ��ݣ�����綾�ޱȡ�");
	return 1;
}
int ask_jieyao() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("nod "+me->query("id"));
	  command("say ����ҲӦ����Ч���κ�������Ĳ���");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"getjieyao"))
  {
	  command("nod "+me->query("id"));
	  command("say �Ͽ�����������ȥ�ɡ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"jieyao2"))
  {
	  command("nod "+me->query("id"));
	  command("say �������Ǻ��ģ�����Ҫ�嶾��һ����ɫҩ��������һ�����ҿ���");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"qixinghaitang"))
  {
	  command("nod "+me->query("id"));
	  command("say ������Ǻ��ĸ��ҡ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")&& me->query_temp(QUESTDIR3+"jieyao1"))
  {
	  command("nod "+me->query("id"));
	  command("say ���Ǻ�����������ҩ֮һ����ϧ���ֻ���ʯ���������ˡ���Ͽ�ȥ�һ����ɡ�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start"))
  {
    tell_object(me,HIC"���ż��ؽ�����������֢״ת��������أ�Ӧ���Ƕϳ���֮����\n"NOR);
    tell_room(environment(me),HIC"\n"+me->query("name")+"���ż��غͳ�����˵��Щʲô��\n"NOR, ({ me }));
	  command("nod "+me->query("id"));
	  command("say �����Ҳ���Ҿ�����ˣ����Ե���������˵���ֶ�ҩ��ȷ�����ͣ���Ȼ�������̱��������Ǳ���ʹ��һ����ݡ�");
	  command("say ���Ǿ綾�����Ǻ��ģ�������ʦ����ֲ�����ã�ֻ��һ�ų��죬��ϧ���ֻ���ʯ���������ˡ���Ͽ�ȥ�һ����ɡ�\n");
	  me->set_temp(QUESTDIR3+"jieyao1",1);
	  return 1;
  } 
	command("?");
	command("sorry");
	return 1;
}
int ask_qixinghaitang() 
{
	object me = this_player();

  if(me->query(QUESTDIR3+"over"))
  {
	  command("nod "+me->query("id"));
	  command("say ���Ǻ��ģ��ɳ�ν���µ�һ��ݣ�����綾�ޱȡ������ְ취���������Ҳ������֮�١�");
	  return 1;
  } 
  if(me->query(QUESTDIR3+"start")
      && (me->query_temp(QUESTDIR3+"getjieyao")
      ||me->query_temp(QUESTDIR3+"jieyao1")
      ||me->query_temp(QUESTDIR3+"jieyao2")
      ||me->query_temp(QUESTDIR3+"askqixinghaitang"))
      )
  {
	  command("sigh "+me->query("id"));
	  command("say ���Ǻ��ģ��ɳ�ν���µ�һ��ݣ�����綾�ޱȡ������ְ취���������Ҳ������֮�١�");
	  return 1;
  } 
  command("say ���Ǻ��ģ��ɳ�ν���µ�һ��ݣ�����綾�ޱȡ�");
	return 1;
}
int ask_hufei() 
{
  message_vision(HIC"$N��Ĭ�ܾõ����Ҳ���ʶ�����......\n"NOR,this_object());
	return 1;
}
