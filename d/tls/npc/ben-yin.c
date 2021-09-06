//cool@SJ,990605
//added by tangfeng 2004
inherit F_MASTER;
inherit NPC;
#include <ansi.h>

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"
#define QUESTDIR6 "quest/�����˲�/�书/"

string askduanyu();
string tianlonghelp();
string asksave();
string askxiaofeng();
string askjiumozhi();
void new_happen(object me);
string ask_kurong();

void create()
{
        set_name("�����ʦ", ({ "benyin dashi","benyin","dashi"}) );
        set("nickname", "����������");
	set("long", "һλ�����ü����ɮ����һϮ��˿ľ�����ġ�\n"+
			"�����׼ұ������У������ʦӦ�ǵ������������۵��׼��常��\n");
	set("gender", "����" );
        set("attitude", "friendly");
        set("age", 69);
        set("str", 25);
        set("int", 26);
        set("con", 28);
        set("dex", 26);
	set("unique", 1);

	set("class", "bonze");
	set("shen", 10);
        set("jing", 2000);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("jiali", 100);
        set("qi", 3000);
        set("max_qi", 3000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("combat_exp", 1350000);

        set_skill("qiantian-yiyang", 165);
        set_skill("tianlong-xiang", 165);
        set_skill("yiyang-zhi", 150);
        set_skill("duanjia-jianfa",170);
        set_skill("buddhism", 165);
        set_skill("literate", 120);
        set_skill("parry", 160);
        set_skill("finger", 165);
        set_skill("sword", 160);
        set_skill("dodge", 165);
        set_skill("kurong-changong", 100);
        set_skill("force", 160);
        set_skill("liumai-shenjian", 120);
        set_skill("medicine", 110);
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("sword", "duanjia-jianfa");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");
        create_family("������", 13, "����");
	set("inquiry", ([
		"name": "ƶɮ���Ǳ���",
		"����Ժ" : "����Ժ���껨��������������",
		"����" : "���ٴ�ʦ������Ժ����",
		"���ٴ�ʦ" : "���ٴ�ʦ������Ժ����",
		"������" : (: ask_kurong :),
		"����Ժ" : (: ask_kurong :),
            		"����" : (: askduanyu :),
		            "����" : "������Ǵ���",
		            "������" : "�������������£�����μ���ѧ�����֮�ء�",
		            "��������" : (: tianlonghelp :),
		            "Ӫ��" : (: asksave :),
		            "���" : (: asksave :),
		            "����" : "�����˳���Ľ�ݡ������壬�˵�һ���ú���",
		            "Ӫ�ȶ���" : (: asksave :),
		            "Ӫ������" : (: askxiaofeng :),
		            "Ľ�ݸ�" : "�����˳���Ľ�ݡ������壬��˵Ľ�ݹ����꼶���ᣬȴ����������",
		            "Ľ�ݲ�" : "����˵�ǣ�����Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		            "�Ħ��" : (: askjiumozhi :),
		            "������" : "��˵������������߾�ѧ����Ҫ���������������á�",
        ]) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat",({
              (: perform_action, "finger.sandie" :),
        }));
        setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object("/d/tls/obj/nianzhu")->wear();
        carry_object("/d/tls/obj/jiasha")->wear();
        carry_object("/d/tls/obj/sengxie")->wear();
}

string ask_kurong()
{
	object me,ob;
	mapping ob_fam,my_fam;
	ob=this_player();
	me=this_object();
	ob_fam = (mapping)ob->query("family");
	my_fam = (mapping)me->query("family");

	if ((ob_fam && ob_fam["family_name"] != "������")||ob->query("class") != "bonze")
		return ("�Բ����㲻��ȥ���ſ��ٴ�ʦ��\n");
	if (ob_fam["generation"] == (my_fam["generation"] + 1)){
		return ("���ֺ��ܣ�������·����һ���֣������Ĳ���������������������һ�������������͵��� \n");
	} 
	else return ("�㱲�ֲ���������ȥ�ݼ����ٴ�ʦ�� \n");
}

#include "ben.h";

void init()
{
	object me,obj1,obj2;
	me = this_player();
	::init();
	if (interactive(me) && living(me)) {
	 	if(me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"kill_dizi"))
    {
    	command("look "+me->query("id"));
    	command("touch "+me->query("id"));
    	command("say ����λ"+RANK_D->query_respect(me) +"��æ�����µ��ɸ��������ˡ�"); 
    }
	 	if(me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"caught") && !me->query(QUESTDIR2+"over"))
    {
    	command("sigh");
    	command("say �����ӱ�ץ��������Ǻã��ҷ�ȱ�����Ը���Ӽ������డ��"); 
    }
	
	if(me->query(QUESTDIR2+"start") 
		&& !me->query_temp(QUESTDIR2+"caught_") 
		&& !me->query_temp(QUESTDIR2+"caught") 
		&& !me->query(QUESTDIR2+"over")
		&& me->query_temp(QUESTDIR2+"kill_dizi"))
    {
    	command("look "+me->query("id"));
    	command("touch "+me->query("id"));
    	command("say ��Щ��λ"+RANK_D->query_respect(me) +"��æ�����µ��ɸ��������ˡ�"); 
      tell_object(me,HIG"\n���߽�������ȴ��������������ַǷ�����������������һ��������ɮ�µ��¾����Ħ���ˣ�����һ����Ȼ���Ǵ������Ӷ�����\n"
                          "�书֮�ߣ����Ϻ�����\n"NOR);
      if(!(obj1=present("duan yu",this_object()))||!(obj1=present("zhongnian nanzi",this_object())))
      {
  	     obj1=new("/d/dali/wuliang/npc/dy");
		 obj1->set_name("����", ({ "duan yu", "duan","yu"}) );
		 obj1->set("title",HIB"���������������"NOR);
		 obj1->set("long", "�����������֮�ӡ�");	
  	     obj1->move(environment(me));
      }
      if(!(obj2=present("jiumo zhi",this_object())))
      {
  	     obj2=new("/kungfu/class/xueshan/jiumozhi");
  	     obj2->move(environment(me));
      }
      message_vision(HIC"ֻ�������н����ݺᣬ�������裬����������Ѹ�׼����໥��ײ�������Ħ��ֻ���ö����ھ�Խ��Խǿ������Ҳ�Ǳ仯Ī�⣬\n"
                        "��ʱ�Դ����⣬���ʲű��򡢱�����˵ľ��ལ�д���ͬ������ʵ��׽�������Բ�֪�����ǲ�������·����������෱����\n"
                        "��ʽ������Σ������ָ�Ҵ̣�������ʲô�Դ������ˣ����¼Ⱦ��һڣ����������о�Ȼ����������һ��������֣����յ�����\n"
                        "��ȡ���衣��ͻȻ�������������������е�������ס���� \n\n"NOR,me);   
         
      message_vision(HIM"\n�����������У�ֻ����ȴ������������Ȼ���������շ���ֻ����ָһ̧�򻳶�ָȥ��$N�������в��ã�̧����ȥ�Ħ�������о���\n\n"NOR,me);   
	  me->start_busy(1);
	  remove_call_out("new_happen");
	  me->set_temp(QUESTDIR2+"caught_",1);
      call_out("new_happen",6, me);
    }
	} 
}
void new_happen(object me)
{
  object obj1,obj2,ob;
  ob = this_object();
  if(!me) 
  {
	  command("?");
	  if((obj1=present("duan yu",environment(ob))))
		  destruct(obj1);
	  if((obj1=present("zhongnian nanzi",environment(ob))))
		  destruct(obj1);
	  if((obj1=present("jiumo zhi",environment(ob))))
		  destruct(obj1);
	  return;
  }
  if(environment(ob)!=environment(me)) 
  {
	  command("say ��ô�ؼ�ʱ��"+me->name()+"�ںδ���");
	  me->delete(QUESTDIR2+"start");
	  me->delete_temp("quest/�����˲�");
	  me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
	  command("heng");
	  return;
  }
  
  if(!(obj1=present("duan yu",environment(ob)))&& !(obj1=present("zhongnian nanzi",environment(ob))))
  {
	  command("ah");
	  command("say �����أ���ô�죬�����Ħ�ǣ�˭���������أ�");
	  me->delete(QUESTDIR2+"start");
	  me->delete_temp("quest/�����˲�");
	  me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
	  command("?");
	  tell_object(me,HIR"������֪���٣�����ʧ�ܡ�\n"NOR);
	  if((obj2=present("jiumo zhi",environment(ob))))
	  {
		  message_vision(HIG"\n$N�ƺ�Ҳ�е�Ī�����ת���뿪�ˡ�\n"NOR,obj2);
		  destruct(obj2);
	  }
	  return;
  }
  
  if(!(obj2=present("jiumo zhi",environment(this_object()))))
  {
	  command("ah");
	  command("say �Ħ���أ���ȻĪ�����������ˣ�");
	  me->delete(QUESTDIR2+"start");
	  me->delete_temp("quest/�����˲�");
	  me->delete_temp("quest/busy");//�����ͻ��־ȡ�� 
	  command("?");
	  tell_object(me,HIR"��������޷�չ����\n"NOR);
	  if((obj1=present("duan yu",environment(ob))))
	  {
		  message_vision(HIG"\n$N���˵�����������ת���뿪�ˡ�\n"NOR,obj1);
		  destruct(obj1);
	  }
	  return;
  }
  
  if(me->query(QUESTDIR2+"start") 
	  && me->query_temp(QUESTDIR2+"caught_") 
	  && !me->query_temp(QUESTDIR2+"caught") 
	  && !me->query(QUESTDIR2+"over")
	  && me->query_temp(QUESTDIR2+"kill_dizi"))
  {
 
    message_vision(HIY"\n��Ȼ���Ħ�Ǽ������������֮ɫ����������ʱ��æ���ң�ȫȻ��֪���ƣ�����΢�����㼴������ϣ���ȭ�������ϻ�ȥ�������\n"
                        "Ħ�ǻ�ȭ�򵽣��㼴ë��ë�ŵ����ȥ���Ħ�����Ʒ�������ץס�����ؿڡ����Ѩ����������ʱȫ�������������á��Ħ��\n"
                        "������ָ�ֵ�������Ȫ��������׵���������š�������Ѩ���Ħ�ǵ���������˵��������λСʩ�����мǵ������񽣵�ͼ�ס�ԭ��\n"
                        "��ͼ���ѱ����ٴ�ʦ��ȥ��Сʩ�����ǻ�ͼ�ף���Ľ������Ĺǰ�����������ˣ�Ҳ��һ�����������ﴦ����ǰ���������嵶��ץ\n"
                        "ס�����˳���Ĳ�������⡣\n\n"NOR,me);  
   	command("@@");
    message_vision(HIY"\n�����仯ʵ�ڳ�������֮�⣬�������Ƴ�������ѧ֮�������д���������ȴҲ�������벻���������������׾ٵ��ֵ���������\n"
                        "�Ħ����������֮ʱ���Ѿ��������ˡ��������ǰ��Ҫ���ˣ��������������嵶��ס���޷����ϡ�\n\n"NOR,me);  
   	command("wah");
    message_vision(HIC"\n�Ħ�ǳ�Ц˵������������ͼ�ף����û�ͼ�ס�Ľ����������������飬�ɲ�����į�ˣ�������б����������һ���죬��Ĳ���õ�\n"
                        "������������������΢�ϣ�����һ�����̰㱼�����У�ɲ�Ǽ䲻֪ȥ����ͱ���˫˫���������Ħ����Ȼ��Զ��ȴ�����ÿ��ٳ�\n"
                        "�ϵ�������׷�����½���磬һƮ���ɡ����Ǳ��δ�ʦ�����������У���׷�ϡ� \n\n"NOR,me);
    me->set_temp(QUESTDIR2+"caught",1);
	destruct(obj1);
	destruct(obj2);
   	return;
  }
}
string askjiumozhi()
{
	object me;
	object *obj;
	int x;
	me = this_player();
	if (me->query(QUESTDIR1+"over") && !me->query(QUESTDIR2+"start"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵�������µ�һ��ɮ�Ħ�ǽ����������·𷨽����������Ҵ���֮�Ұ���";
  }
	if (me->query(QUESTDIR2+"start") && !me->query_temp(QUESTDIR2+"jiumozhi")&&!me->query(QUESTDIR2+"over"))
	{
      //����ʱ��;���������
      //ʱ��һ�죬����500K
      if(me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
   	                 return "��л"+RANK_D->query_respect(me) +"������塣�����æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�";
      if(me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<500000)
  	                return "��"+RANK_D->query_respect(me) +"Ŀǰ�ľ������Ŀǰ�������Ҳ�ﲻ��ʲôæ������ץ�������ɣ�";
      //�趨��־
	  tell_object(me,HIW"\n����֪���������Ħ������ެ���Ļ�����������ֻ��˵���ߴ��ǻۣ���ͨ�𷨣������书Ҳ�ǳ��ߡ�ֻ�����\n"NOR);
  	  tell_object(me,HIW"����֮�£�ȷʵ��ͨ�����������񽣾�����������������֮�����������Ҫ����������������۸����ˡ�\n"NOR);
  	  tell_object(me,HIC"��������������۸��˵��о���ȷ�����ֲ��ݣ����²��ţ�ҲҪ����һ�ܡ�\n\n"NOR);
	  command("touch "+me->query("id"));
  	  obj = users();
	  x = sizeof(obj);
	  while(x--) {
		  if ( obj[x]->query_temp(QUESTDIR2+"jiumozhi") && obj[x]!=me) 
			  return "��������"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�Ѿ��ڰ����ˣ�"+RANK_D->query_respect(me) +"����ץ�������ɣ�";		  
	  }
	  me->set(QUESTDIR+"time",time());
	  me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));        

  	  me->set_temp(QUESTDIR2+"jiumozhi",1);
	  me->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
	  log_file("quest/TLBB", sprintf("%s(%s) ��ʼ�����˲������¾�Ԯƪ�����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
	  return "���������Ҳ���Ǿ��������ĸ�ɮ�ˣ������ز�ͨ������������ǿҪ�˾���ֻ�������߲��������߲��ƣ�\n"
		         "���º����С�������������������ʦ��������ִ�֡������������"+RANK_D->query_respect(me) +"������ֻ����������ʧ���ˡ�\n"
		         "\n"NOR+HIG+me->name()+"��ͷ�����п���ʦ��������ִ����á������ȵ��������ſ�һ����"NOR;
  }
	if (me->query(QUESTDIR2+"start")&& me->query(QUESTDIR2+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "��л"+RANK_D->query_respect(me) +"������ֻ����ħɮ��Ϊ��ެ����һ�𷨸�ɮ��";
  }

  command("nod");
  return "���������Ħ������ެ���Ļ�������������˵���ߴ��ǻۣ���ͨ�𷨣������书Ҳ�Ǿ��ˡ�";
}
string askxiaofeng()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR3+"start"))
  {
  	  command("hoho");
  		return "�����˳���Ľ�ݡ������壬�˵�һ���ú�������Ԯ��֮˵��";
  }
	if (me->query(QUESTDIR3+"start") && !me->query(QUESTDIR3+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }

	if (me->query(QUESTDIR3+"bad"))
	{
  	  command("heng");
  	  command("? "+me->query("id"));
                  return "���壬�Ѳ��������ȳ���ԭ��������ν��Ȳ�֪���⣡";
  }
	if (me->query(QUESTDIR3+"start") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR4+"start"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR4+"start")&& !me->query(QUESTDIR4+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR4+"start") && me->query(QUESTDIR4+"over"))
	{
  	  command("haha "+me->query("id"));
		  return "��˵��һս��"+me->query("name")+"�����������֣��˵���������";
  }
  command("hoho");
	return "�����˳���Ľ�ݡ������壬�˵�һ���ú�������Ԯ��֮˵��";
}
string asksave()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR1+"start") &&!me->query(QUESTDIR2+"start"))
  {
  	  command("hoho");
  		return "С����������ϲ��ѧ��ֻ�����׾���ƽ�׽��ˣ�����Ԯ��֮˵��";
  }
	if (me->query(QUESTDIR1+"start") && !me->query(QUESTDIR1+"wuliangover")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵��ǰ��ʱ��С���Ӻ����������ǳ���һ��������δ�лؼң���֪"+RANK_D->query_respect(me) +"�ɷ��������һ�¡�";
  }
	if (me->query(QUESTDIR1+"start") && me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
		  return "�ҷ�ȱ���ֻ���Դ���ٹȻ�����С���Ӿ����㱣���֪���кζ������ܺ������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ���С��������ٹȻ�����������Ѫ�������������죬�ű�������������������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ�����Ȼ�ǳ��Ħ����ȸ��֣���Ը���Ӽ������డ��";
  }
  command("hoho");
	return "С����������ϲ��ѧ��ֻ�����׾���ƽ�׽��ˣ�����Ԯ��֮˵��";
}
string askduanyu()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR1+"start" )&&!me->query(QUESTDIR2+"start"))
  {
  	  command("hoho");
  		return "���������������������������Ĺ��ӣ���˵���ʴ��������Դ���ֻ��������ϲ��ѧ��ֻ�����׾���";
  }
	if (me->query(QUESTDIR1+"start") && !me->query(QUESTDIR1+"wuliangover")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵��ǰ��ʱ��С���Ӻ����������ǳ���һ��������δ�лؼҡ�";
  }
	if (me->query(QUESTDIR1+"start") && me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���������������漰����֮����";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
		  return "�ҷ�ȱ�����л"+RANK_D->query_respect(me) +"���С���ӡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ���С��������ٹȻ�����������Ѫ�������ű������������¿��ٳ�������������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh "+me->query("id"));
		  return "�ҷ�ȱ�����Ȼ�ǳ��Ħ����ȸ��֣���Ը���Ӽ������డ��";
  }
  command("hoho");
	return "���������������������������Ĺ��ӣ���˵���ʴ��������Դ���";
}
string tianlonghelp()
{
	object me;

	me = this_player();
  if(!me->query(QUESTDIR1+"over"))
  {
  	  command("haha");
  		return "���������Ҷμ���ѧ�����֮�أ��������ƣ��벻ҪΣ��������";
  }  
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
	   return "�����º���ԭ�ٸ�Ӧ��û�а���ϵ��"+RANK_D->query_respect(me) +"��������С��ͨ����";
	}
  if (me->query(QUESTDIR1+"over") && !me->query(QUESTDIR2+"start"))
	{
  	  command("sigh");
	  tell_object(me,HIY"ֻ�������ɴӻ���ȡ��һ������õ��ż㣬���������С�����˹����������ص��أ�������������֮����\n"NOR);
  	  tell_object(me,HIY"��ʶ��д���ǣ�����ʳ�ʥ��ס�̡����ӽ����г���ż㣬Ҳ��һ�ż����Ľ�㣬����������д������˵����\n"NOR);
  	  tell_object(me,HIG"���������Ľ�ݲ�������ᣬ�������ѣ�̸�۵����书��Ľ���������¶Թ��¡������񽣡������Ƴ磬����δ\n"NOR);
  	  tell_object(me,HIG"�ðݹ�Ϊ��������Ľ���������ţ���ʹ���ѣ�Ϊ��֪���������������þ����ٻ���Ľ������Ĺǰ��������ȡ��\n"NOR);
  	  tell_object(me,HIG"��ȴΪ�ҡ�ƶɮ�Ե��Թ������ﻹ����δ�ҿ�����ȡҲ������ĩ��������ѩɽ�����������Ħ�Ǻ�ʮ�ٰݡ���\n"NOR);
  	  command("heng");

  	  command("look "+me->query("id"));
  	  if(me->query("combat_exp")<3000000)		  return ""+RANK_D->query_respect(me) +"���������ˣ�ֻ��ֻ�����Ħ���书��ǿ����Ҳ�޷���æ���١�";
  	  if(me->query("shen")<0)		  return ""+RANK_D->query_respect(me) +"���������ˣ�ֻ��......��";

  	  me->set(QUESTDIR2+"start",1);
	  return "�������"+RANK_D->query_respect(me) +"��æ��ֻ������������ε����������ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("heng");
		  return "�ҷ�ȱ�����ħɮ��Ȼ����۸��Ҵ������ˣ���Ϊ��ެ����һ�𷨸�ɮ��";
  }
	if (me->query(QUESTDIR2+"over"))
	{
  	  command("thank "+me->query("id"));
		  return "�ҷ�ȱ�����л"+RANK_D->query_respect(me) +"�����ⳡ����Σ���������Ҵ���С���ӵ��Խ�ȡ�";
  }
  command("hoho");
	return "�ҷ�ȱ������������Ҷμ���ѧ�����֮�أ��������ƣ��벻ҪΣ��������";
}
