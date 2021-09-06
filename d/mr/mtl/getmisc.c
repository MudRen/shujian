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
	set("short",HIW"娘缳玉洞-杂项部"NOR);
	set ("long",@long
这是曼佗罗山庄存放武功秘籍的地方，一排排书架上整齐的摆放着各种书
籍，似乎都与如何研修更高深的杂项武学有关。
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
           return notify_fail("这里只能参悟杂学(misc)部分!\n");

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_gift") )
                  return notify_fail("你正忙着呢。\n");

if (me->query_temp("canwu_now") )
       return notify_fail("你正忙着呢。\n");

if (me->query("relife/gifts/now") )
       return notify_fail("你还是先把自己的天赋分配完毕以后再来吧。\n");
        
        if (query_temp("canwu") )
        return notify_fail("有人正在参悟呢，你等一会把。\n");


     if( me->query("relife/gifts/total")<20)
                 return notify_fail("藏书内容太深奥了，你参悟天赋不够20点，暂时无法理解。\n");


     if( me->query("combat_exp",1)<50000000)
                 return notify_fail("藏书内容太深奥了，你实战经验不够50M，暂时无法理解。\n");
       
                 
       message_vision( HIW"$N仔细的翻看着书架上的藏书，对里面瀚如烟海的杂学内容很感兴趣。\n"NOR,me);
        message_vision( HIW"$N一头扎进书堆里.不停的翻看着。。 \n"NOR, me);
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
          if(random(2)) tell_object(me,HIG"\n你仔细的研读着书里面的内容，只觉得耳目一新...\n"NOR);
                   else tell_object(me,HIY"\n你研读着书里千奇百怪的杂学内容，心里有所领悟...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"眉头紧皱，似乎在思索着什么...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_gift");
         me->start_busy(10);     
  message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“原来如此，原来如此。”\n"NOR,me); 
  tell_object(me,HIR"\n你通过本次研读，对闯荡江湖的见识更加深了一步！\n"NOR);
  tell_object(me,HIR"\n想起了自己以前走过的不少弯路，不禁大感后悔！你决定背叛师门，重入江湖！\n"NOR);
  tell_object(me,HIW"你获得了一次重新拜师的机会！\n"NOR);
  tell_object(me,HIR"\n你的天赋属性被重置了！你可以立即重新分配自己的天赋属性\n"NOR); 
  tell_object(me,HIR"\n你重新审视起自己年轻时代笑傲江湖的梦想！\n"NOR);    
  tell_object(me,HIW"你进入了快速成长的黄金时代（24小时精英）！\n"NOR);    

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

//这里是基本

	sname=filter_array( allskills, (: sort_basic :) );
	allskills-=sname;

//这里是特殊
	sname=allskills;
	j = sizeof(sname);
         if(j>0)   for(i=0; i<j; i++) {

                 if ( me->query_skill(sname[i],1) >=0 )
                             	
                         if(sname[i]!="kongming-quan")    //空明拳
                         if(sname[i]!="jiuyin-zhengong")
                         if(sname[i]!="jiuyin-shenfa")
                         if(sname[i]!="xuanyin-jian")
                         if(sname[i]!="jiuyin-shenzhua")
                         if(sname[i]!="jiuyin-baiguzhua")
                         if(sname[i]!="yinlong-bian")
                         if(sname[i]!="cuixin-zhang")
                         if(sname[i]!="dafumo-quan")      //9yin系列
                         if(sname[i]!="wuhu-duanmendao")  //五虎
                         if(sname[i]!="miaojia-jianfa")
                         if(sname[i]!="hujia-daofa")
                         if(sname[i]!="lengquan-shengong") //冷泉系列
                         if(sname[i]!="jinshe-jianfa")
                         if(sname[i]!="jinshe-zhangfa")
                         if(sname[i]!="wudu-yanluobu")     //金蛇系列
                         if(sname[i]!="lingbo-weibu")
                         if(sname[i]!="beiming-shengong")  //北冥系列
                         if(sname[i]!="kuihua-shengong")
                         if(sname[i]!="pixie-jian")        //葵花系列
                         if(sname[i]!="hamagong")
                         if(sname[i]!="hamabu")
                         if(sname[i]!="lingshe-zhangfa")
                         if(sname[i]!="lingshe-quanfa")    //蛤蟆系列
                         if(sname[i]!="wuxing-zhen")       //五行阵
                         if(sname[i]!="ningxue-shenzhuao") //凝血
                         if(sname[i]!="qianzhu-wandushou") //千蛛
                         if(sname[i]!="yangjia-qiang")     //杨家枪 
                         if(sname[i]!="taizhu-quan")       //太祖拳 
                         if(sname[i]!="wuxingbu")          //五行步
                         if(sname[i]!="shenzhao-jing")
                         if(sname[i]!="tangshi-jianfa")    //连城诀
                         if(sname[i]!="xixing-dafa")       //吸星大法
                         if(sname[i]!="taixuan-jing")      //太玄经
                         if(sname[i]!="jindao-heijian")    //金刀黑剑
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
        me->set("title",HIC"一代宗师"NOR);
       i = me->query("relife/gifts/now",1); 
       j = me->query("relife/gifts/total",1);
       me->set("relife/relifed",1);
    tell_object(me,HBBLU"\n你本次参悟共耗费了" + HIW + chinese_number( exp ) + HIR + "实战经验，你现在总共有" + HIW + chinese_number( i ) + HIR + "的额外的天赋！\n"NOR);
    tell_object(me,HBRED"\n请立即使用(addgift)进行分配！\n"NOR);

      log_file("canwu/getmisc", sprintf("%s(%s) 耗费%dM经验，重置天赋点数为%d，当前经验：%d。\n", 
       me->name(1),
       me->query("id"),
       exp/1000000,
       me->query("relife/gifts/total",1),
       me->query("combat_exp")) );
  me->delete_temp("canwu_now");   
 delete_temp("canwu");   
   }

}

