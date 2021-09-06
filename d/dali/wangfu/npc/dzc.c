// cool 980310
// duan1.c
// Modify By River 98/11
//COOL@SJ,990828
// tangfeng@SJ 2004

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"
#define QUESTDIR6 "quest/�����˲�/�书/"

string ask_join();
string ask_duan();
string strike();
string fenglu();
string ask_save();
string tianlonghelp();
string askxiaofeng();
string askjiumozhi();

void create()
{
	set_name("������", ({ "duan zhengchun", "duan", "master" }) );
	set("title", "������");
	set("nickname","������ү");
	set("gender", "����" );
	set("age", 44);
	set("str", 22);
	set("con", 23);
	set("dex", 23);
	set("int", 25);
	set("per", 28);
	set("attitude", "friendly");


	set("max_qi", 3000);
	set("max_jing", 1800);
	set("eff_jingli", 1800);
	set("neili", 3000);
	set("qi", 3000);
	set("jingli", 1800);
	set("max_neili", 3000);
	set("jiali", 50);

	set("rank_info/respect", "������ү");
	create_family("������", 13, "�׼ҵ���");

	set("long",
	"�������Ǹ��൱�ߴ�����������������Ǹ����������ҵ�������ʿ��Ⱥ��\n"
	"���Ų²�����ǰ����������ŵ������˾��Ǵ�����ү��\n");

	set("combat_exp", 1100000);
	set("score", 50000);

	set("chat_chance_combat", 30);
	set("chat_msg_combat",({
		(: perform_action, "sword.fenglei" :),
		(: exert_function, "qi" :)
	}));

	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("force", 150);
	set_skill("cuff", 150);
	set_skill("literate", 120);
	set_skill("sword", 160);
	set_skill("duanjia-jianfa", 160);
	set_skill("strike", 150);
	set_skill("qingyan-zhang", 150);
	set_skill("qiantian-yiyang", 150);
	set_skill("duanjia-quan", 150);
	set_skill("tianlong-xiang", 150);
	set_skill("finger", 150);
	set_skill("yiyang-zhi", 160);
	set_skill("buddhism", 100);

	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "qingyan-zhang");
	map_skill("sword", "duanjia-jianfa");
	map_skill("cuff", "duanjia-quan");
	map_skill("force", "qiantian-yiyang");
	map_skill("strike", "qingyan-zhang");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("strike","qingyan-zhang");
	prepare_skill("cuff","duanjia-quan");

	set("inquiry", ([
		"����" : (: ask_duan :),
		"name": "���������Ҿ��Ƕ��������ѵ����������������ĺ��ӣ�",
		"here": "�����������������",
		"������" : "���������Ҷμ���ѧ�����֮�أ���������������¿ɲ�����ô���׵�.",
		"������" : (: ask_join :),
		"��������" : (: ask_join :),
		"�Ʒ���Ҫ" : (: strike :),
		"���Ʒ�" : (: strike :),
	//	"ٺ»" :  (: fenglu :),
		"Ӫ��" : (: ask_save :),
		"���" : (: ask_save :),
		"Ԯ��" : (: ask_save :),
		"��Ԯ" : (: ask_save :),
		"save" : (: ask_save :),
		"���" : (: ask_save :),		
		"����" : "������Ǵ���",
		"������" : "���������Ҷμ���ѧ�����֮�أ���������������¿ɲ�����ô���׵�.",
		"��������" : (: tianlonghelp :),
		"����" : "�����˳���Ľ�ݡ������壬�˵�һ���ú���",
		"Ӫ�ȶ���" : (: ask_save :),
		"��Ԯ����" : (: ask_save :),
		"Ԯ�ȶ���" : (: ask_save :),
		"��Ԯ����" : (: askxiaofeng :),
		"Ԯ������" : (: askxiaofeng :),
		"�������" : (: askxiaofeng :),
		"Ӫ������" : (: askxiaofeng :),
		"Ľ�ݸ�" : "�����˳���Ľ�ݡ������壬��˵Ľ�ݹ����꼶���ᣬȴ����������",
		"Ľ�ݲ�" : "����Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		"�Ħ��" : (: askjiumozhi :),
         "������" : "��˵������������߾�ѧ����Ҳδ�ܵü���",          
	]));

	setup();
	carry_object("/d/dali/npc/obj/huangpao")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}
void init()
{
	object ob,me;
	ob =this_object();
	me = this_player();
	::init();
	if (interactive(me) && living(me)) {
		if(this_player()->query("quest/dali"))
		{
			tell_object(me,HIY"\n������Quest��ϵͳ�Զ�ת����־������\n"NOR);
			if(this_player()->query("quest/dali/fail"))
			{
				this_player()->set(QUESTDIR6+"fail",this_player()->query("quest/dali/fail"));
				tell_object(me,HIY"ԭ��"+chinese_number(this_player()->query("quest/dali/fail"))+"��ʧ�ܼ�¼ת���ɹ���\n"NOR); 
				this_player()->delete("quest/dali/fail");
			}
			if(this_player()->query("quest/dali/time"))
			{
				this_player()->set(QUESTDIR+"time",this_player()->query("quest/dali/time"));
				tell_object(me,HIY"�ϴν���ʱ���־ת���ɹ���\n"NOR);  
				this_player()->delete("quest/dali/time");
			}
			if(this_player()->query("quest/dali/shanlu"))
			{
				this_player()->set(QUESTDIR1+"pass_shanlu",1);
				tell_object(me,HIY"�ɹ�ͨ�������ֱ�־ת���ɹ���\n"NOR);  
				this_player()->delete("quest/dali/shanlu");
			}
			if(this_player()->query("quest/dali/yuxiang"))
			{
				this_player()->set(QUESTDIR6+"yuxiang",1);
				tell_object(me,HIY"��ͷ�����־ת���ɹ���\n"NOR);
				this_player()->delete("quest/dali/yuxiang");
			}
			if(this_player()->query("quest/dali/pass"))
			{
				this_player()->set(QUESTDIR6+"pass",1);
				this_player()->set(QUESTDIR6+"yuxiang",1);
				tell_object(me,HIY"�貨΢����־ת���ɹ���\n\n"NOR);
				this_player()->delete("quest/dali/pass");
			}
			this_player()->delete("quest/dali");
			tell_object(me,HIY"\n�¾�ϵͳ�Զ�ת��������\n\n"NOR);
		}
		if(this_player()->query(QUESTDIR6+"pass") && !this_player()->query(QUESTDIR1+"wuliangover"))
					this_player()->set(QUESTDIR6+"yuxiang",1);
		if(me->query(QUESTDIR1+"over"))
			command("thank "+me->query("id"));
		if(!me->query_condition("killer")&& me->query_temp(QUESTDIR1+"see_duanyu1")&&!me->query(QUESTDIR1+"wuliangover"))
		{
			command("look "+me->query("id"));
			tell_object(me,HIY"\n����ǰ����"+ob->name()+"��˵������ɽ���ֶ�������ɷ��ģ�\n"NOR);
			command("oh");
			command("jump "+me->query("id"));
			message_vision(HIC"$n��$N��ʾ��ϵĸ�л��\n", me, this_object());
			command("touch "+me->query("id"));
			command("say ����Ҳ��ȫ�����ˣ������⼸��Ȯ�Ӿͻ�����ġ�"); 
			me->delete_temp("quest/busy");//����ϵͳ��ͻ��־
			me->delete_temp("quest/�����˲�");   
			me->set(QUESTDIR1+"wuliangover",1);   
			//�趨��־
			me->set(QUESTDIR+"time",time());
			me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
		}
	} 
}

string ask_duan()
{
	object me;
	object *obj;
	int x;
	me = this_player();
	if(me->query_condition("killer"))
	{
	   command("fear "+me->query("id"));
           return "С������ԭ�ٸ�Ӧ��û�а���ϵ��"+RANK_D->query_respect(me) +"��������С��ͨ����";
	}
  if(!me->query(QUESTDIR1+"start" )&&!me->query(QUESTDIR2+"start"))
  { 
      message_vision(HIC"$N����¶�����ߵ���ɫ��\n", this_object());
  	  command("heng");
	  obj = users();
	  x = sizeof(obj);
	  while(x--) {
		  if ( (obj[x]->query_temp(QUESTDIR1+"jianying")
                          ||obj[x]->query_temp(QUESTDIR1+"start"))
			  && obj[x]!=me) 
			  return "������"+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�Ѿ��ڰ����ˣ�"+RANK_D->query_respect(me) +"������ô�ż���";		  
	  }
  	  //�趨��־
  	  me->set(QUESTDIR+"time",time());
  	  me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 	
  	  me->set(QUESTDIR1+"start",1);
      me->set_temp(QUESTDIR1+"start",1);
	  me->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
	  log_file("quest/TLBB", sprintf("%s(%s) ��ʼ�����˲���һ���֡����飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
	  return "С������ѧ�䣬���ҳ��˼������ҳ����ˣ���......���Ų��Ұ���";
  }
	if (me->query(QUESTDIR1+"start") && !me->query(QUESTDIR1+"wuliangover")&& !me->query(QUESTDIR1+"over"))
	{
	  message_vision(HIC"$N����¶�����ߵ���ɫ��\n", this_object());
  	  command("sigh");
  	  command("shrug "+me->query("id"));
	  return "ǰ��ʱ������˵������ɽ��������С������֪���������ںδ���";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"wuliangover")&& !me->query(QUESTDIR1+"over"))
	{
 
  	  command("sigh");
  	  message_vision(HIC"$N����¶�����ĵ���ɫ��\n", this_object());
  	  //ʱ��һ��
  	  if(me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
	  {
		  if(random(2)) return "�����æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�";
		  else return "�����⼸��Ϳ��ܻ����ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�";
	  }
	  me->set_temp(QUESTDIR1+"2_start",1);
	  return "С����ǰ���Ĵ���˵��Ϻ�����°���ˣ����������跨Ӫ������������Ŀǰ��������ɽ������һ��ʯ���ڡ�";
	}
	if (me->query(QUESTDIR1+"start")&& me->query_temp(QUESTDIR1+"2_start") && !me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  message_vision(HIC"$N����¶�����ĵ���ɫ��\n", this_object());
  	  command("shrug "+me->query("id"));
	  return "����̽����С��ȷʵ��������ɽ������һ��ʯ���ڣ�������ֻ��Ҫ��һ���ˡ�";
  }
  if (me->query(QUESTDIR1+"start") && me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
  	  command("look "+me->query("id"));
  	  command("nod "+me->query("id"));
  	  message_vision(HIC"$n��$N��ʾ��ϵĸ�л��\n", me, this_object());
	  return "����̽����С��ȷʵ��������ɽ������һ��ʯ���ڣ���������"+RANK_D->query_respect(me) +"���������޴󰭡�";
  }
  if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
  	  message_vision(HIC"$n��$N��ʾ��ϵĸ�л��\n", me, this_object());
	  return "��л"+RANK_D->query_respect(me) +"���С����ֻ������ٹ�֮������һֱ�������ű��������������ȥ�ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "С������ٹȻ�����������Ѫ�������������죬�ű������������ȥ�ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh");
		  return "��Ȼ�ǳ��Ħ����ȸ��֣���ԸС���������డ��";
  }
  command("nod "+me->query("id"));
	return "��������Ȯ�ӣ���֪���������¡�";
}

string ask_save()
{
	object me;
	object *obj;
	int i,j,x;
	i=random(5)+2;
	j=random(4)+3;
	me=this_player();

  if(!me->query(QUESTDIR1+"start" ))
  {
  	  command("?");
  		return "С������ֻ�����Ѿ���ƽ�׽��ˣ�Ԯ��֮˵����֮˵��";
  }
	if (me->query(QUESTDIR1+"start") && !me->query(QUESTDIR1+"wuliangover")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("shrug "+me->query("id"));
		  return "ǰ��ʱ������˵������ɽ��������С�������̰�棬������ȥ�ɡ�";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"wuliangover")&& !me->query_temp(QUESTDIR1+"2_start")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("sigh");
		  return "С��������˸�Ī������ĵ��ӣ������ʲô�Ϻ����㣿�����ǵ��İ���ǧ��Ҫ��ʲô���ӡ�";
  }
	if (me->query(QUESTDIR1+"start")&& me->query_temp(QUESTDIR1+"2_start") && !me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
		if ( me->query("shen") < 0)
		           return ("�ҿ�" + RANK_D->query_respect(me) +"�����а֮�����������Ĵ����һ��ļ�ϸ��");
    	if ( me->query("combat_exp") < 1500000)
		           return ("�Ĵ���˶��Ǿ�������,"+RANK_D->query_respect(me) +"�ƺ��书���������Ĵ�����භ��������֮�ǡ�");
  		me->set_temp(QUESTDIR1+"step",i);
	  	me->set_temp(QUESTDIR1+"steps",j);
  	  command("look "+me->query("id"));
   	  //����ʱ��;���������
  	  //ʱ��һ��
  	  if(me->query(QUESTDIR+"time")&&time()-me->query(QUESTDIR+"time")<86400)
	  {
		  if(random(2)) return "�����æ�ˣ�"+RANK_D->query_respect(me) +"������Ϣȥ�ɣ�";
		  else return "���������Ĵ�������ߣ�����»���ӳ����飬"+RANK_D->query_respect(me) +"ǧ�򲻵�³ç��";
	  }
	  //���Ǻܶ����ƣ����ﾭ��������һ��
	  if(me->query(QUESTDIR+"combat_exp")&&me->query("combat_exp")-me->query(QUESTDIR+"combat_exp")<100000)
		  return "��"+RANK_D->query_respect(me) +"Ŀǰ�ľ������Ŀǰ�������Ҳ�ﲻ��ʲôæ������ץ�������ɣ�";

	  obj = users();
	  x = sizeof(obj);
	  while(x--) {
		  if ( obj[x]->query_temp(QUESTDIR1+"yingjiu")&& obj[x]!=me) 
			  return ""+obj[x]->query("name")+RANK_D->query_respect(obj[x]) +"�Ѿ��ڰ����ˣ�"+RANK_D->query_respect(me) +"����ץ�������ɣ�";		  
	  }

  	  //�趨��־
  	  me->set(QUESTDIR+"time",time());
  	  me->set(QUESTDIR+"combat_exp",me->query("combat_exp"));
  	  command("touch "+me->query("id"));
  	  me->set_temp(QUESTDIR1+"yingjiu",1);
	  me->set_temp("quest/busy",1);//������ϵͳ��ͻ��־
	  log_file("quest/TLBB", sprintf("%s(%s) ��ʼ׼��Ӫ�ȶ�������һ�£������飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
	  return ("��Ȼ"+ RANK_D->query_respect(me) +"���������������绢�������ҵ�֪���������Ĵ����֮��\n"+
			"������������������ɽ������һ��ʯ���ڣ�ֻ��·��ʮ���ն�֮ǰΪ��̽��·�ߣ�\n"+
			"������ʧ�ü������¡�����ȥ������ȥ����ɽ·�ϵ�һ��СϪ����������\n"+
			"��������"+chinese_number(j)+"�������"+chinese_number(i)+"�Ȼ��ᵽһ����ɽ���������Ҫ���������ˡ�\n\n"+
			"������˵�������ˣ�׼��һ�£�Ϊ�˲������Է����м�Ҫ�������ж���·��С�ġ�");
  }
  if (me->query(QUESTDIR1+"start") && me->query_temp(QUESTDIR1+"yingjiu")&& !me->query(QUESTDIR1+"over"))
	{
  	  command("look "+me->query("id"));
  	  command("touch "+me->query("id"));
                  return "��"+RANK_D->query_respect(me) +"���������޴󰭡�";
  }
	if (me->query(QUESTDIR1+"start") && me->query(QUESTDIR1+"over")&& !me->query(QUESTDIR2+"start"))
	{
  	  command("thank "+me->query("id"));
		  return "��л"+RANK_D->query_respect(me) +"���С����ֻ������ٹ�֮������һֱ�������ű��������������ȥ�ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over")&& !me->query_temp(QUESTDIR2+"caught"))
	{
  	  command("sigh "+me->query("id"));
		  return "С������ٹȻ�����������Ѫ�������������죬�ű������������ȥ�ˡ�";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh "+me->query("id"));
  	  command("look "+me->query("id"));
		  return "��Ȼ�ǳ��Ħ����ȸ��֣���ԸС���������డ��";
  }
  command("nod "+me->query("id"));
	return "С������ֻ�����Ѿ���ƽ�׽��ˣ�Ԯ��֮˵����֮˵��";
}
string askjiumozhi()
{
	object me;
	me = this_player();
	if (me->query(QUESTDIR1+"over") && !me->query(QUESTDIR2+"start"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵�������µ�һ��ɮ�Ħ�ǽ����������·𷨽����������Ҵ���֮�Ұ���";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh");
  	  command("? "+me->query("id"));
		  return "��ħɮ��Ȼ����۸��Ҵ������ˣ���Ϊ��ެ����һ�𷨸�ɮ����ν����������ȫ��һ�ɺ��ԡ�";
  }
	if (me->query(QUESTDIR2+"start")&& me->query(QUESTDIR2+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "�Ħ����Ϊ�����һ�𷨸�ɮ����ν����������ȫ��һ�ɺ��ԡ�";
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
		  return "��˵������飬ֻ���漰�����������֮����ʵ�ڲ��ò��֡�";
  }

	if (me->query(QUESTDIR3+"bad"))
	{
  	  command("heng");
  	  command("? "+me->query("id"));
                  return "���壬�Ѳ��������ȳ���ԭ��������ν��Ȳ�֪���⡣";
  }
	if (me->query(QUESTDIR3+"start") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR4+"start"))
	{
  	  command("sigh");
  	  command("shrug "+me->query("id"));
		  return "��˵������飬ֻ���漰�����������֮����ʵ�ڲ��ò��֡�";
  }
	if (me->query(QUESTDIR4+"start")&& !me->query(QUESTDIR4+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "������С��֮���֣���ȻҪ�ȡ���λ"+RANK_D->query_respect(me) +"������һ��������μҵ������Ԯ����";
  }
	if (me->query(QUESTDIR4+"start") && me->query(QUESTDIR4+"over"))
	{
  	  command("haha "+me->query("id"));
		  return "��һս����ʹ�죬"+me->query("name")+"�����������֣��˵���������";
  }
	return "�����˳���Ľ�ݡ������壬�˵�һ���ú�������Ԯ��֮˵��";
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
	if (me->query(QUESTDIR1+"over") && !me->query(QUESTDIR2+"start"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵�������¸�ɮ�Ħ�ǲ��ս����������£���֪��ϲ�ǻ���";
  }
	if (me->query(QUESTDIR2+"start") && !me->query(QUESTDIR2+"over"))
	{
  	  command("sigh");
		  return "��ħɮ��Ȼ����۸��Ҵ������ˣ���Ϊ��ެ����һ�𷨸�ɮ��";
  }
	if (me->query(QUESTDIR2+"over"))
	{
  	  command("thank "+me->query("id"));
	  return "��л"+RANK_D->query_respect(me) +"�����ⳡ����Σ����������ֶ�ӵ��Խ�ȡ�";
  }
  command("hoho");
	return "���������Ҷμ���ѧ�����֮�أ��������ƣ��벻ҪΣ��������";
}
string strike()
{
	mapping fam = this_player()->query("family");
	object ob;
	if(!fam || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
	if(this_player()->query_skill("strike",1) > 30)
		return "����Ʒ��Ѿ���һ�������ˣ��Ȿ�����ûʲô�ã�����������ĵ��Ӱ�";
	ob = unew("/d/dali/obj/book-strike");
	if(!clonep(ob))
		return "�������ˣ����ɵġ��Ʒ���Ҫ�����ڴ˴���";
	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return "�������ˣ����ɵġ��Ʒ���Ҫ�����ڴ˴���";
	}
	ob->move(this_player());
	return "�ðɣ��Ȿ���Ʒ���Ҫ�����û�ȥ�ú����С�";
}

string ask_join()
{
	object me;
	object ob;
	ob=this_player();
	me=this_object();
	if (ob->query("tls"))
		return "���Ѿ��������³��ҵ����ˣ��ιʻ�Ҫ�ʴ��£�";

//	if (ob->query("combat_exp") > 100000)
//		return "��������ڴ�����Ҫ���������˲ţ��Ͳ�Ҫȥ�����³��Ұɡ�";

	if(ob->query_temp("tls_app"))
		return "�Ҳ����Ѿ��Ƽ���ȥ������������ô����ȥ����";

	if((string)ob->query("gender") == "Ů��" )
		return "�������书��Ҫ����֮�壬С����ɲ��հ�! ";

	if((int)ob->query_skill("qiantian-yiyang",1) < 120  )
		return RANK_D->query_respect(ob) +"����Ǭ��һ����̫��,����ѧϰ�ߵȼ��Ĺ���!";

	if ( ob->query("job_time/����") + ob->query("job_time/����")  < 50)
		return "�ҿ���Ϊ���������������Ļ���������Ŭ�����ɣ�";

	if ( ob->query_int() < 30 )
		return "��������ѧ��£��ҿ���������ƺ������������޷������ô�ߵĹ���!";

	if( ob->query("marry"))
		return "�㶼�Ѿ�����ˣ�Ҫȥ���ң����������ô�죿";

	ob->set_temp("tls_app",1);
	command ("say �����������ģ���λ�ֵܼ�ȻΪ�Ҵ������������ô����,������Ƽ���ȥ�����£�");
	return "�Ҽ�������һ�⣬�����͵��������˻���ʦ��������ٸ�ȥ��!";
}

string fenglu()
{
	object ob=this_player();
	mapping fam = ob->query("family");
	int gold = 0, fenglu;

	if (!fam || fam["family_name"] != "������")
		return "��λ"+ RANK_D->query_respect(ob) +"�����Ҵ�����ĳ����ѵ�Ҳ�����ô����ٺ»��";

	if( ob->query("tls"))
		return "��λ"+ RANK_D->query_respect(ob) +"�Ѿ������ˣ���Ҫ��ٺ»������";

	switch (fam["generation"]) {
		case 13:
			gold += 500;
		case 14:
			gold += 800;
			break;
		default:
			return "��λ"+ RANK_D->query_respect(ob) +"�ڴ���ʱ�仹̫�̣��ȹ���ʱ������ðɡ�";
	}
	fenglu = ob->query("age") * 12 + ob->query("month");
	if (ob->query("fenglu") >= fenglu)
		return "��λ"+RANK_D->query_respect(ob) +"���²����Ѿ��ù�ٺ»�ˣ���ô�������ã�";
	gold *= ob->query_skill("qiantian-yiyang", 1);
        if (ob->query_skill("force", 1) < 216)  return "�������û��ٺ»��";
	ob->set("fenglu", fenglu);
	command ("pat " + ob->query("id"));
	message_vision("$N����$n"+MONEY_D->money_str(gold)+"��\n", this_object(), ob);
	MONEY_D->pay_player(ob, gold);
	return "�����㱾�µ�ٺ»����λ"+ RANK_D->query_respect(ob) +"�úøɰ���";
}

void attempt_apprentice(object ob)
{
	object me=this_object();
	mapping fam = ob->query("family");
	if( (string)ob->query("gender") == "Ů��" ){
		command ("say ���������书��Ҫ����֮�壬С�����ҿɲ��հ�!");
		return;
	}
	if (ob->query("tls")){
		command ("say ���Ѿ��������³��ҵ����ˣ��Ҳ����������ˣ�\n");
		return;
	}
	if( (int)ob->query_skill("qiantian-yiyang",1) < 80  ){
		command ("hmm");
		command ("say ��Ǭ��һ�������֮��ҿɲ�����?");
		return;
	}
	if(ob->query_int() < 30){
		command("say ѧһ��ָ֮�˱���������ߣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ�������");
		return;
	}
     if(fam["master_name"] == "������"){
		command("haha");
		command("say "+RANK_D->query_respect(ob)+"�����ֳ���ǰ��������"+RANK_D->query_self(me)+"����������Ϊͽ��");
		return;
	}
	command("smile");
	command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
	command("recruit " + ob->query("id") );
	if (!ob->query("qinwang")) {
		this_object()->set("title",HIC "��������������ҽ�" NOR);}
	else
		{
		this_object()->set("title", HIW "�����"+ ob->query("qinwang")+NOR);}
}

void recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	 ob->set("class", "officer");
}
