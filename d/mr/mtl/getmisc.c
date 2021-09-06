// mr up_misc_skills.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;

string *valid_type = ({
"force", "parry",  "dodge", "unarmed","claw",
"cuff",  "finger", "strike","hand",   "leg",
"sword", "blade",  "dagger","brush",  "spear",
"hook",  "stick",  "staff", "club",   "throwing",
"whip",  "axe",    "hammer","bow",
});

int sort_skill2(string sk) 
{
	return (SKILL_D(sk)->type() == "knowledge" && SKILL_D(sk)->type2() == "worker");
}

int sort_skill(string sk)
{
	return (SKILL_D(sk)->type() != "martial" && SKILL_D(sk)->type() != "array");
}

int sort_basic(string sk)
{
	return member_array(sk, valid_type)!=-1;
}


void create()
{
	set("short",HIW"������-���"NOR);
	set ("long",@long
������٢��ɽׯ����书�ؼ��ĵط���һ�������������İڷ��Ÿ�����
�����ƺ�����������޸������������ѧ�йء�
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}

void init()
 {
         add_action("do_canwu", "canwu"); 
         add_action("do_canwu", "yandu");
 }



int do_canwu(string arg)
 {
     object me = this_player();

     if(arg != "misc" )
           return notify_fail("����ֻ�ܲ�����ѧ(misc)����!\n");

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_gift") )
                  return notify_fail("����æ���ء�\n");

if (me->query_temp("canwu_now") )
       return notify_fail("����æ���ء�\n");

if (me->query("relife/gifts/now") )
       return notify_fail("�㻹���Ȱ��Լ����츳��������Ժ������ɡ�\n");
        
        if (query_temp("canwu") )
        return notify_fail("�������ڲ����أ����һ��ѡ�\n");


     if( me->query("relife/gifts/total")<20)
                 return notify_fail("��������̫����ˣ�������츳����20�㣬��ʱ�޷���⡣\n");


     if( me->query("combat_exp",1)<50000000)
                 return notify_fail("��������̫����ˣ���ʵս���鲻��50M����ʱ�޷���⡣\n");
       
                 
       message_vision( HIW"$N��ϸ�ķ���������ϵĲ��飬����������̺�����ѧ���ݺܸ���Ȥ��\n"NOR,me);
        message_vision( HIW"$Nһͷ���������.��ͣ�ķ����š��� \n"NOR, me);
       me->start_busy(100);               
       me->set_temp("canwu_now",1); 
       set_temp("canwu",1);            
     call_out("thinking",5, me );
         return 1;

 }


int thinking(object me)
{

 	mapping skl, lrn, map;

	string *sname, *mapped, *allskills, str = "";
  int i,j,p,exp;

  p = me->query("str",1)+ me->query("dex",1)+ me->query("con",1)+ me->query("int",1)-80;

 if(!me) return 0;
	
 if(me->query_temp("con_gift")<(3+random(3)))
       {  me->add_temp("con_gift",1);
          if(random(2)) tell_object(me,HIG"\n����ϸ���ж�������������ݣ�ֻ���ö�Ŀһ��...\n"NOR);
                   else tell_object(me,HIY"\n���ж�������ǧ��ٹֵ���ѧ���ݣ�������������...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"üͷ���壬�ƺ���˼����ʲô...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_gift");
         me->start_busy(10);     
  message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
  tell_object(me,HIR"\n��ͨ�������ж����Դ��������ļ�ʶ��������һ����\n"NOR);
  tell_object(me,HIR"\n�������Լ���ǰ�߹��Ĳ�����·��������к�ڣ����������ʦ�ţ����뽭����\n"NOR);
  tell_object(me,HIW"������һ�����°�ʦ�Ļ��ᣡ\n"NOR);
  tell_object(me,HIR"\n����츳���Ա������ˣ�������������·����Լ����츳����\n"NOR); 
  tell_object(me,HIR"\n�������������Լ�����ʱ��Ц�����������룡\n"NOR);    
  tell_object(me,HIW"������˿��ٳɳ��Ļƽ�ʱ����24Сʱ��Ӣ����\n"NOR);    

if( me->query( "family/family_name") ) 
               me->set("cw_mp/"+me->query("family/family_name"),1);

        me->set("str",10);
        me->set("dex",10);
        me->set("con",10);
        me->set("int",10);
        me->delete("gf_gives");
        me->delete("tls");
        me->delete("class");
        me->set("relife/gifts/total", p+10 );
        me->set("relife/gifts/now",   p+50 );
        me->delete("relife/gifts/used");
        
 
 
  skl = me->query_skills();
  allskills  = sort_array( keys(skl), (: strcmp :) );
	sname=filter_array( allskills, (: sort_skill2 :) );
	allskills-=sname;
	sname=filter_array( allskills, (: sort_skill :) );
	allskills-=sname;

//�����ǻ���

	sname=filter_array( allskills, (: sort_basic :) );
	allskills-=sname;

//����������
	sname=allskills;
	j = sizeof(sname);
         if(j>0)   for(i=0; i<j; i++) {

                 if ( me->query_skill(sname[i],1) >=0 )
                             	
                         if(sname[i]!="kongming-quan")    //����ȭ
                         if(sname[i]!="jiuyin-zhengong")
                         if(sname[i]!="jiuyin-shenfa")
                         if(sname[i]!="xuanyin-jian")
                         if(sname[i]!="jiuyin-shenzhua")
                         if(sname[i]!="jiuyin-baiguzhua")
                         if(sname[i]!="yinlong-bian")
                         if(sname[i]!="cuixin-zhang")
                         if(sname[i]!="dafumo-quan")      //9yinϵ��
                         if(sname[i]!="wuhu-duanmendao")  //�廢
                         if(sname[i]!="miaojia-jianfa")
                         if(sname[i]!="hujia-daofa")
                         if(sname[i]!="lengquan-shengong") //��Ȫϵ��
                         if(sname[i]!="jinshe-jianfa")
                         if(sname[i]!="jinshe-zhangfa")
                         if(sname[i]!="wudu-yanluobu")     //����ϵ��
                         if(sname[i]!="lingbo-weibu")
                         if(sname[i]!="beiming-shengong")  //��ڤϵ��
                         if(sname[i]!="kuihua-shengong")
                         if(sname[i]!="pixie-jian")        //����ϵ��
                         if(sname[i]!="hamagong")
                         if(sname[i]!="hamabu")
                         if(sname[i]!="lingshe-zhangfa")
                         if(sname[i]!="lingshe-quanfa")    //���ϵ��
                         if(sname[i]!="wuxing-zhen")       //������
                         if(sname[i]!="ningxue-shenzhuao") //��Ѫ
                         if(sname[i]!="qianzhu-wandushou") //ǧ��
                         if(sname[i]!="yangjia-qiang")     //���ǹ 
                         if(sname[i]!="taizhu-quan")       //̫��ȭ 
                         if(sname[i]!="wuxingbu")          //���в�
                         if(sname[i]!="shenzhao-jing")
                         if(sname[i]!="tangshi-jianfa")    //���Ǿ�
                         if(sname[i]!="xixing-dafa")       //���Ǵ�
                         if(sname[i]!="taixuan-jing")      //̫����
                         if(sname[i]!="jindao-heijian")    //�𵶺ڽ�
                         if(sname[i]!="qixian-wuxingjian")
              //         if(sname[i]!="wuhu-duanmendao")
 
                             me->delete_skill(sname[i]);
                  }


        
               exp = 40000000;
       if(me->query("registered") == 3) exp=40000000;
       if(me->query("y-card-vip"))         exp=38000000;
       if(me->query("buyvip") )             exp=36000000; 
       me->add("combat_exp",-exp);
        me->delete("family",1);                  
        me->add_condition("db_exp",8640);
        me->set("age",18);
        me->set("shen",1);
        me->set("title",HIC"һ����ʦ"NOR);
       i = me->query("relife/gifts/now",1); 
       j = me->query("relife/gifts/total",1);
       me->set("relife/relifed",1);
    tell_object(me,HBBLU"\n�㱾�β��򹲺ķ���" + HIW + chinese_number( exp ) + HIR + "ʵս���飬�������ܹ���" + HIW + chinese_number( i ) + HIR + "�Ķ�����츳��\n"NOR);
    tell_object(me,HBRED"\n������ʹ��(addgift)���з��䣡\n"NOR);

      log_file("canwu/getmisc", sprintf("%s(%s) �ķ�%dM���飬�����츳����Ϊ%d����ǰ���飺%d��\n", 
       me->name(1),
       me->query("id"),
       exp/1000000,
       me->query("relife/gifts/total",1),
       me->query("combat_exp")) );
  me->delete_temp("canwu_now");   
 delete_temp("canwu");   
   }

}

