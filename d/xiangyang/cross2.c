#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�϶��ֽ�");
        set("long", @LONG
�����Ǿ���������������ͨ�����źͶ��ŵĶ���·�ڣ���ʱ���ж������
��ʿ��������ȥ�����ϳ��ǿ���ȥ���ϣ��򶫳��ǿ���ȥ���ա����ա����淽
����һ���ߴ����¥��
LONG
        );
        set("outdoors", "����");
        set("xyjob",1);
        set("exits", ([
                "east" : __DIR__"djie1",
                "north" : __DIR__"dpailou",
		"west" : __DIR__"njie1",
        ]));
        set("objects",([
		__DIR__"npc/wuxiuwen" : 1,
        ]));
        set("incity",1);
	setup();
}


void init()
{
    mapping fam;
    object me = this_player();
    int time,total ;
    string vip;
    if(!userp(me)) return;

time = time() - me->query("char_check",1);	
total =  me->query("SJ_Credit",1)+me->query("SJ_Credit_Used",1);
fam=me->query("family");

if( time >=86400 ){
 
      if(me->query("buyvip")) {
                   me->set("registered", 3);    
                   me->set("vip/vip_start_time",time());     
                   me->set("vip/vip_time",time());       
                   me->add("vip/vip_time",365*24*3600);
                               }
  
         if(me->query("registered")<=3) vip = HIG"��ͨ��Ա"NOR;
     if(me->query("m-card-vip"))   vip = HIM"�¿����"NOR;
     if(me->query("y-card-vip"))   vip = HIR"�꿨���"NOR;
    if(me->query("buyvip"))     {  vip = HIW"�������"NOR;
me->set("y-card-vip",1);}
  	
  me->set("char_check",time());

 log_file( "static/check_CREDIT",sprintf("%s(%s)  | ʣ��:%s  �ۼ�ʹ��:%s,�ܼ�ӵ��%d�������츳%d������EXP%d������ȼ�%s��Ŀǰ����%d��\n", 
             me->name(),
             me->query("id"),
             chinese_number(me->query("SJ_Credit")),
             chinese_number(me->query("SJ_Credit_Used")),
              total,
              me->query("relife/gifts/total"),
              me->query("relife/exp_ext"),
              vip,
              me->query("combat_exp")
                      ));
            }

//������5w�Զ�תVIP
 if(me->query("SJ_Credit_Used")>=50000 && !me->query("buyvip"))  me->set("buyvip",1);

if (!me->query("quest/jiuyin1/pass")){
      if( me->query_skill("jiuyin-zhengong",1)>221) me->set_skill("jiuyin-zhengong",221); 
      if( me->query_skill("jiuyin-shenfa",1)>221) me->set_skill("jiuyin-shenfa",221);
                                      }
 
if ( !me->query("quest/pixie/pass") || me->query("gender") != "����"){
    if (me->query_skill("pixie-jian",1) >= 240) me->set_skill("pixie-jian",240); 
                                      }

if(me->query("oyf/son")) { me->delete("oyf/son");
me->set("oyf_son",1);}

if(!fam || fam["family_name"]!="ȫ���" && fam["family_name"]!="��Ĺ��")
 { 
 if(me->query_skill("anran-zhang")) me->delete_skill("anran-zhang");
 if(me->query_skill("haotian-zhang")) me->delete_skill("haotian-zhang");
 if(me->query_skill("xiantian-gong")) me->delete_skill("xiantian-gong");
 if(me->query_skill("jinyan-gong")) me->delete_skill("jinyan-gong");
 if(me->query_skill("quanzhen-jianfa")) me->delete_skill("quanzhen-jianfa");
  }
           
if(!fam || fam["family_name"]!="����")
 { 
 if(me->query_skill("qishang-quan")) me->delete_skill("qishang-quan");
 if(me->query_skill("shenghuo-shengong")) me->delete_skill("shenghuo-shengong");
  }
if( me->query_skill("yeqiu-quan",1) )  me->delete_skill("yeqiu-quan");
if(!fam || fam["family_name"]!="���չ�" && fam["family_name"]!="��ң��")
 { 
 if(me->query_skill("liuyang-zhang")) me->delete_skill("liuyang-zhang");
 if(me->query_skill("zhemei-shou")) me->delete_skill("zhemei-shou");
  }


}
