// duanyu.c ����
// COOL@SJ,990827
// Modified by tangfeng 2004
// ����Ķ����漰������������һ������������һ����ʯ���һ���ڴ����°�����
// By Spiderii@ty ����ʱ������
inherit F_MASTER;
#include <ansi.h>
inherit NPC;

#define QUESTDIR "quest/�����˲�/"
#define QUESTDIR1 "quest/�����˲�/�貨΢��ƪ/"
#define QUESTDIR2 "quest/�����˲�/����Ӫ��ƪ/"
#define QUESTDIR3 "quest/�����˲�/��������ƪ/"
#define QUESTDIR4 "quest/�����˲�/���ɾ�Ԯƪ/"
#define QUESTDIR5 "quest/�����˲�/��������ƪ/"
#define QUESTDIR6 "quest/�����˲�/�书/"

string tianlonghelp();
string askxiaofeng();
string askjiumozhi();
string ask_name();
int ask_home();
int ask_save();
void outroom(object me);
void dest(object me,object ob);
void greeting(object me);

void create()
{
        set_name("��������", ({"qingnian nanzi", "nanzi", "man"}));
        set("gender", "����");
        set("age", 20);
        set("long", "����һ���������ӣ���ͷɢ������������������ֻϵ��һ���̿㣬¶��\n"
                    "���������ȣ������Լ⣬�����ƺ���Щ����\n");
        set("attitude", "peaceful");
        set("str", 15);
        set("per", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        set("no_quest", 1);

        set("inquiry", ([
		"����" : (: ask_name :),
		"name" : (: ask_name :),
		"���" : (: ask_save :),
		"����" : (: ask_save :),
		"�ȶ���" : (: ask_save :),
		"������" : (: ask_save :),
		"���" : (: ask_save :),
		"���" : (: ask_save :),
		"save" : (: ask_save :),
		"������" : "���������ҹؽ����ġ�\n",
		"��ʦ" : "��....���ҵ�ʦ�������ӡ����Ӻ�ׯ�ӣ����ǵ�ѧ���һ�ûѧȫ�ء�\n",
		"����" : "�������Ҽң��Ҽ��ڴ���",
		"������" : "�������Ǵ���μ���ѧ�����֮�ء�",
		"��������" : (: tianlonghelp :),
		"����" : "�Ҵ�����尡���˵�һ���ú���",
		"Ӫ������" : (: askxiaofeng :),
		"Ľ�ݸ�" : "Ľ�ݹ���ȷ���佭���Ĳɣ�ʫ���黭�����������书���ǹھ����¡�",
		"Ľ�ݲ�" : "����˵�ǣ�����Ľ�ݲ����Ľܲţ���ϧӢ�����š�",
		"�Ħ��" : (: askjiumozhi :),
		"������" : "��������߾�ѧ��",
		"������" : "�����ҵ�����",
		"���׷�" : "������������ʲô���飿",
		"������" : "�����Ҳ�����ʲô���飿",
		"����" : "������������ʲô���飿",

		"�ؼ�" : (: ask_home :),
		"go home" : (: ask_home :),

		//�����񽣵�quest������������һ�룬�ڿ��ٳ��������в�������
        ]));

        set("jing", 10000);
        set("max_jing", 10000);
        set("jingli", 10000);
        set("eff_jingli", 10000);
        set("qi", 50000);
        set("max_qi", 20000);
        set("neili", 60000);
        set("max_neili", 40000);
        set("jiali",500);
        
        set("combat_exp", 15000000);
        set_skill("buddhism", 250);            
        set_skill("daode-jing", 250);                   
        set_skill("literate", 300);                
        set_skill("force", 600);                
        set_skill("beiming-shengong", 600);     
        set_skill("dodge", 600);                
        set_skill("lingbo-weibu", 600);         
        set_skill("parry", 300);
        set_skill("finger", 300);
        set_skill("yiyang-zhi", 200);
        set_skill("liumai-shenjian", 200);
        map_skill("parry", "yiyang-zhi");
        map_skill("finger", "yiyang-zhi");
        map_skill("force", "beiming-shengong");
        map_skill("dodge", "lingbo-weibu");
        setup();        
}
void init()
{
	object me;
	me = this_player();
	::init();
	if (interactive(me) && living(me) 
		&& !me->query_condition("killer")
		&& me->query(QUESTDIR1+"start") ) {
		me->start_busy(2);
        remove_call_out("greeting"); 
		call_out("greeting",2,me);
	} 
}
void greeting(object me)
{
	if(!me) return;
	if(environment(this_object())!=environment(me)) return;

	if(!me->query_condition("killer")&&me->query(QUESTDIR1+"start") 
			&& !me->query_temp(QUESTDIR1+"see_duanyu1")
			&& !me->query_temp(QUESTDIR1+"see_duanyu2")
			&& !me->query(QUESTDIR1+"wuliangover")
			&& me->query_temp(QUESTDIR1+"jianying"))
    {
		//����
		  message_vision(HIC"\n$Nһת����һ����ȴ��������ȴ��һ������վ������ǰ���ճյĴ����ţ��Ǳ��龹Ȼ�ɰ��������ɾ��ɳա�\n"NOR, me);  
		  log_file("quest/TLBB", sprintf("%s(%s) �貨΢�������������������飺%d��\n", me->name(1),me->query("id"), me->query("combat_exp")) );
		  me->set_temp(QUESTDIR1+"see_duanyu2",1);
		  me->start_busy(1);
		  command("crazy");
		  command("say");
    }
	
	if(!me->query_condition("killer")
		&& me->query(QUESTDIR2+"start") 
		&& me->query_temp(QUESTDIR2+"pushdown") 
		&& !me->query(QUESTDIR2+"over"))
    {
		  message_vision(HIC"\n$N�������ң�����һ���������ӣ�����������ض����㿴���о�����һ�㱻���������ӡ�\n\n"NOR, me);                      
		  command("ah "+me->query("id"));
		  command("look "+me->query("id"));
		  command("heng");
		  command("say");
		  command("say �����˲���ò�࣬��ħɮ����һ����ɮ��ȴ��Ϊ����������"); 
		  me->start_busy(1);
    }
}
string ask_name()
{
		set_name("����", ({ "duan yu", "duan","yu"}) );
		set("title",HIG"���������������"NOR);
		set("long", HIG"�������ң�ȴ���ɷ�����ˣ�����Ҳ�Ǹ����ӵܡ����Һ��ܡ�"NOR); 
		command("nod");
		return "���±��Ƕ�����";
}
int ask_home()
{
    object me,ob;
    ob=this_object();
	me=this_player();
	if(!me->query_condition("killer")
		&& me->query(QUESTDIR1+"start") 
		&& me->query_temp(QUESTDIR1+"see_duanyu2")
		&& !me->query_temp(QUESTDIR1+"gohome")
		&& !me->query_temp(QUESTDIR1+"see_duanyu1")
		&& !me->query(QUESTDIR1+"wuliangover")
		&& me->query_temp(QUESTDIR1+"jianying")
		&& ob->query("id")=="duan yu")
    {
		message_vision(HIY"\n$N������������������������ļ����ǣ����»��ǻ�ȥ��������\n"NOR, me, this_object());
		command("oh");
		command("consider");
		me->start_busy(1);
		command("say");
		me->set_temp(QUESTDIR1+"gohome",1);
		call_out("outroom",6,me);
		return 1;
    } 
	command("consider");
	me->start_busy(1);
	command("say");
	command("say ��Ҳ���ȥ��ֻ��.......");
	command("shout");
    return 1;
}
void outroom(object me)
{
  object ob=this_object();
  if(!me) return;
  if(!me->query(QUESTDIR1+"start")) return;
  if(!me->query_temp(QUESTDIR1+"gohome")) return;
  if(me->query_temp(QUESTDIR1+"see_duanyu1")) return;
  if(me->query(QUESTDIR1+"wuliangover")) return;

  if(environment(ob)!=environment(me)) 
  {
  	command("say ���أ�"+me->name()+"�ղŲ��ǻ�����");
	me->delete("quest/�����˲�/�貨΢��ƪ");
  	command("say �һ����Ȼ�ȥ�ˣ������Ͳ���һ���ż��ˡ�");
  	command("sigh");
    me->set(QUESTDIR+"time",time());
 	me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 	
	destruct(ob);
  	return;
  }
  
  command("look "+me->query("id"));
 
  if(me->query("gender")=="Ů��")
  {
	  if(me->query("per")>26)
	  {
		  command("say ��λ��㣬��ȻҲ��ôƯ���������еú�������һƴ�����������񾫹�Ҳ̫��ɫ�����ˡ�");
		  command("points");
		  tell_object(me,HIC"\n�������ӿ�������ʱ��ֻ�����۹����ת�����������ƻ���һ�㡣����һ������ͷ���ң�������۹��ƺ�Ҳ�������ƶ�������\n"
			  "��վ����һ�ߣ�������۹�ʼ�������㣬�۹��е���ɫ��������׽������ϲ�ư�������������ֿ��������Ȼ���ˡ�\n"NOR);
		  tell_room(environment(me),HIC"תͷȴ��"+me->query("name")+"Ҳ��һ����ɫ�ֵֹ����ӣ�Ҳ�ƺ���ʲô����ס���Ƶġ�\n"NOR, ({ me })); 
		  tell_object(me,HIC"\n����������������ã����תͷ���������Ϲ�ĥƽ����������ʮ���֣����ǡ�ׯ�ӡ��еľ��ӣ��󶼳��ԡ���ң�Ρ���������������\n"
			  "����ˮ���������֡���ƪ���ʷ�Ʈ�ݣ����Լ�ǿ�����������̳ɣ�ÿһ�ʶ�����ʯ�ڼ�����硣��ĩ����һ�����ƣ�����ң��Ϊ��\n"
			  "ˮ���顣���������£��˼�����Ҳ������\n"NOR);
		  tell_object(me,HIR"\n����һ�ᣬ����ס�ѿڶ����������������·����������ɫ����˵�����Ӽ��ˣ����񲻶�����������ΪŮ����Ҳ����ɫ��㱡���\n"
			  HIY"\n��ͻȻ��Ȼ��˫ϥ�򵹰���ȥ�ĳ嶯�� \n"NOR);
		  command("ah "+me->query("id"));
		  command("touch "+me->query("id"));	  
	  }
	  else
	  {
		  command("say "+me->query("name")+"����λ��㣬������ϸ��������������̫��ɫ�����ˡ�");
		  command("points");
		  tell_object(me,HIC"\n�������ӿ�������ʱ��ֻ�����۹����ת�����������ƻ���һ�㡣����һ������ͷ���ң�������۹��ƺ�Ҳ�������ƶ�������\n"
			  "��վ����һ�ߣ�������۹�ʼ�������㣬�۹��е���ɫ��������׽������ϲ�ư�������������ֿ��������Ȼ���ˡ�\n"NOR);
		  tell_room(environment(me),HIC"תͷȴ��"+me->query("name")+"Ҳ��һ����ɫ�ֵֹ����ӣ�Ҳ�ƺ���ʲô����ס���Ƶġ�\n"NOR, ({ me })); 
		  tell_object(me,HIC"\n����������������ã����תͷ���������Ϲ�ĥƽ����������ʮ���֣����ǡ�ׯ�ӡ��еľ��ӣ��󶼳��ԡ���ң�Ρ���������������\n"
			  "����ˮ���������֡���ƪ���ʷ�Ʈ�ݣ����Լ�ǿ�����������̳ɣ�ÿһ�ʶ�����ʯ�ڼ�����硣��ĩ����һ�����ƣ�����ң��Ϊ��\n"
			  "ˮ���顣���������£��˼�����Ҳ������\n"NOR);
		  tell_object(me,HIR"\n����һ�ᣬ����ס�ѿڶ����������������·����������ɫ����˵�����Ӽ��ˣ����񲻶�����������ΪŮ�������������Բ�����������\n"
			  HIY"\n��ͻȻ��Ȼ��˫ϥ�򵹰���ȥ�ĳ嶯�� \n"NOR);
		  command("ah "+me->query("id"));
		  command("shrug "+me->query("id"));	  
	  }
  }
  else
  {
 	  command("say "+me->query("name")+"��Ҳ��ͬ�����ˣ�������ϸ��������������̫��ɫ�����ˡ�");
	  command("points");
	  tell_object(me,HIC"\n�������ӿ�������ʱ��ֻ�����۹����ת�����������ƻ���һ�㡣����һ������ͷ���ң�������۹��ƺ�Ҳ�������ƶ�������\n"
	  "��վ����һ�ߣ�������۹�ʼ�������㣬�۹��е���ɫ��������׽������ϲ�ư�������������ֿ��������Ȼ���ˡ�\n"NOR);
	  tell_room(environment(me),HIC"תͷȴ��"+me->query("name")+"Ҳ��һ����ɫ�ֵֹ����ӣ�Ҳ�ƺ���ʲô����ס���Ƶġ�\n"NOR, ({ me })); 
	  tell_object(me,HIC"\n����������������ã����תͷ���������Ϲ�ĥƽ����������ʮ���֣����ǡ�ׯ�ӡ��еľ��ӣ��󶼳��ԡ���ң�Ρ���������������\n"
		  "����ˮ���������֡���ƪ���ʷ�Ʈ�ݣ����Լ�ǿ�����������̳ɣ�ÿһ�ʶ�����ʯ�ڼ�����硣��ĩ����һ�����ƣ�����ң��Ϊ��\n"
		  "ˮ���顣���������£��˼�����Ҳ������\n"NOR);
      if(me->query("gender")=="����") tell_object(me,HIR"\n�㰵�룺����Ҫ����������Ů�ˣ�������һǧ�飬һ��飬Ҳ����Ǽ��֣���ϲ���ޡ��� \n"NOR);
	  tell_object(me,HIR"\n����һ�ᣬ����ס�ѿڶ������������梣������ܻ��������˵һ�仰���ұ�Ϊ����һǧ�飬һ��飬Ҳ����Ǽ��֣���ϲ���ޡ���\n"
		  HIY"\n��ͻȻ��Ȼ��˫ϥ�򵹰���ȥ�ĳ嶯�� \n"NOR);
	  command("ah "+me->query("id"));
	  command("touch "+me->query("id"));
  } 
  command("sigh");
  command("say �һ����Ȼ�ȥ�ˣ������Ͳ���һ���ż��ˡ�");
  command("chat* bye "+me->query("id"));	 
  command("wave "+me->query("id"));
  tell_room(environment(me),HIG"\nֻ���������Ҵ�ææ���뿪��ֻ����ɫ�ƺ������������ᡣ\n\n"NOR, ({}));
  me->set_temp(QUESTDIR1+"see_duanyu1",1);
  destruct(ob);
  return;
}


int ask_save()
{
    object me,ob,obj;
	int i, time;
    me=this_player();
    ob=this_object();
           
       //by Spiderii@ty �����±��,ֻΪ��ֹ��ǰ��lbwb����ҿ�������fan bojuan
       time = time() - me->query("quest/�����˲�/�书/time");
       if ( me->query("quest/�����˲�/�书/time") && time < 86400 ) 
          {
		       message_vision("$N�ƺ�����$n����˼��\n", ob,me);
	         return 1;
		 }


    if(ob->query("id")!="duan yu")
	{
		message_vision("$N�ƺ�����$n����˼������$nҪ��˭��Ī��������ƭ�ҵģ���\n", ob, me);
		command("fear");
		return 1;
	}
	if (!me->query_condition("killer")
		&& me->query(QUESTDIR1+"start") 
		&& !me->query(QUESTDIR1+"over") 
		&& me->query_temp(QUESTDIR1+"kill_duan") 
		&& me->query(QUESTDIR1+"wuliangover"))
	{
		command("nod "+me->query("id"));
		message_vision(HIC"$N����������������Իر���׳ʿ��ѧ��֮�ˣ��������о���������\n"
			+"������ã����������㣬�Ա���֮л�⡣��˵�꣬$N�ӻ�������һ�����¡�\n"
			+"ͻȻ��$N��ʧ��ɫ������Ӵ����ô����������ӣ����ˣ����ˣ�Ī�����⣿����\n"
			+"��ȥ�ɣ��������پͿ�����컯�ˡ�˵�꣬$N��������$n��\n"NOR, ob, me);
		obj=new("/d/dali/obj/dodge_book");
              obj->set("owner", me->query("id"));//By Spiderii@ty �Ӹ����,��ֹBUG
              me->set("quest/�����˲�/�书/time", time()); //�Ӹ����ơ���ֹ������,ֻΪ������ǰ��lbwb����� By Spiderii@ty

		obj->move(me);
		//�趨��־
		me->set(QUESTDIR+"time",time());
		me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 	
		me->delete_temp("quest/�����˲�");
		me->set(QUESTDIR1+"over",1);//����
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		me->add_busy(4);
		i=10+random(10);
		me->add("max_neili",i);
		me->add("combat_exp",me->query_skill("force")+400);
		me->add("mana",me->query_skill("force")/3);
		command("thank "+me->query("id"));
		tell_object(me,HIY"\n����"+NATURE_D->game_time()+"����ǧ��������ڶ�������ٹȽ�ȳ��������"+i+"�����������"+(me->query_skill("force")+400)+"�㾭���"+(int)me->query_skill("force")/3+"��������\n\n");
		log_file("quest/TLBB", sprintf("%s(%s) �貨΢��ƪ��ɡ�������%d�����������%d�㾭�飬%d��������\n", me->name(1),me->query("id"), i,(me->query_skill("force")+400),me->query_skill("force")/3) );
		remove_call_out("dest");
		call_out("dest",5,me,ob);
		return 1;
	}
	if(me->query(QUESTDIR2+"start") && me->query_temp(QUESTDIR2+"pushdown") && !me->query(QUESTDIR2+"over"))
	{
		command("say "+me->query("name")+"�Ѿ��ǵڶ�������ˣ���ķǳ��м��������������п��ʯ��������ȥ��");
		obj=new("/d/zhiye/obj/kuangshi1");
		obj->set_level(5+random(3));
		obj->move(me);
		message_vision("$N����$nһ��"+obj->query("name")+"��\n", ob, me);
    	command("chat* thank "+me->query("id"));
    	command("wave "+me->query("id"));
    	command("bye "+me->query("id"));
		//�趨��־
		me->set(QUESTDIR+"time",time());
		me->set(QUESTDIR+"combat_exp",me->query("combat_exp")); 	
		me->set(QUESTDIR2+"over",1);  //���� 	
		me->delete_temp("quest/�����˲�");
		me->delete_temp("quest/busy");//�����ͻ��־ȡ��
		i=10+random(10);
		me->add("max_neili",i);
		me->add("combat_exp",(me->query_skill("force")+500));
		me->add("mana",me->query_skill("force")/3);
		tell_object(me,HIY"\n����"+NATURE_D->game_time()+"����ǧ��������ڶ����������½�ȳ��������"+i+"�����������"+((int)me->query_skill("force")+500)+"�㾭���"+(int)me->query_skill("force")/3+"��������\n\n");
		log_file("quest/TLBB", sprintf("%s(%s) ����Ӫ��ƪ��ɡ�������%d�����������%d�㾭�飬%d��������%s��\n", me->name(1),me->query("id"), i,(me->query_skill("force")+500),me->query_skill("force")/3,obj->query("name")) );
		destruct(this_object());
		return 1;
	}	
	if(random(2)) command("nod "+me->query("id"));
	else command("jump "+me->query("id"));
	return 1;
}

void dest(object me,object ob)
{
  if(!ob) return;
  if(!me || environment(ob)!=environment(me))
  {
	  destruct(ob);
	  return;
  }
  environment(ob)->set("exits/down","/d/dali/wuliang/midao1");
  message_vision(HIY"$n��Ȼ�����������������ɣ�������������������˴ӵ������˳��� \n"
		+"$n��ϸһ����ԭ���Ǵ�����Ļ����ޡ�����ʯ�ͷ��衣������ǰ����� \n"
		+"���˸���,���������ӣ��������������ˡ����۽�һƳ��������$n������\n"
		+"��������λ̨�֣�����������������λ̨��Ҳ�������ҵģ���ɱ���Ĵ����\n"
		+"��ǰ���ƿ���ʯ���롣�������͡������������־����壬������������ġ�\n"
		+"����˵����ڶ࣬���»�����Ԯ���������˵ز��˾������������Ҵӵص���\n"
		+"�Ͻ��뿪�ɡ������˵�ͷ���ǣ����Ƿ����͡������������µص��뿪����\n"NOR, ob, me);
  destruct(ob);
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
  	  command("sigh "+me->query("id"));
		  return "�����˲���ò�࣬��ħɮ����һ����ɮ��ȴ��Ϊ����������";
  }
	if (me->query(QUESTDIR2+"start")&& me->query(QUESTDIR2+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "�Ħ����Ϊ�����һ�𷨸�ɮ����ν����������ȫ��һ�ɺ��ԡ�";
  }
  command("nod");
	return "���������Ħ������ެ���Ļ�������������˵���ߴ��ǻۣ���ͨ�𷨣������ʶһ�¡�";
}
string askxiaofeng()
{
	object me;
	me = this_player();
  if(!me->query(QUESTDIR3+"start"))
  {
  	  command("nod");
  		return "�Ҵ���������Ӣ�ۣ�����Ԯ��֮˵��";
  }
	if (me->query(QUESTDIR3+"start") && !me->query(QUESTDIR3+"over"))
	{
  	  command("nod "+me->query("id"));
		  return "��˵������飬�ߣ��Ҽȿ�ǰ�����ɡ�";
  }

	if (me->query(QUESTDIR3+"bad"))
	{
  	  command("heng");
  	  command("? "+me->query("id"));
		  return "���壬�Ѳ��������ȳ���ԭ��������ν��Ȳ�֪ʲô��˼�������ʣ�";
  }
	if (me->query(QUESTDIR3+"start") && me->query(QUESTDIR3+"over")&& !me->query(QUESTDIR4+"start"))
	{
  	  command("heng");
		  return "��˵������飬�ߣ��Ҽȿ�ǰ�����ɡ�";
  }
	if (me->query(QUESTDIR4+"start")&& !me->query(QUESTDIR4+"over"))
	{
  	  command("heng");
		  return "��˵������飬�ߣ��Ҽȿ�ǰ�����ɡ�";
  }
	if (me->query(QUESTDIR4+"start") && me->query(QUESTDIR4+"over"))
	{
  	  command("haha "+me->query("id"));
		  return "��һս����ʹ�죬"+me->query("name")+"�����������֣��˵���������";
  }
  command("hoho");
	return "�����˳���Ľ�ݡ������壬�����������Ҵ�磬���Ӣ�ۺú�������Ԯ��֮˵��";
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
		  return "��л"+RANK_D->query_respect(me) +"���һع���";
  }
  command("hoho");
	return "���������Ҷμ���ѧ�����֮�أ��������ƣ��벻ҪΣ��������";
}
