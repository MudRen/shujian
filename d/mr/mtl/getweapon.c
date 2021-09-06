// mr up_uweapon_feature.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIW"娘缳玉洞-神兵部"NOR);
	
        set ("long",@long
这是曼佗罗山庄存放武功秘籍的地方，一排排书架上整齐的摆放着各种书
籍，似乎都与如何淬养神兵利器(cuilian weapon)有关。
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}


void init()
 {
         add_action("do_canwu", "cuilian");
 }



int do_canwu(string arg)
 {
     object me = this_player();
     object wpn;

     if(arg != "weapon")
           return notify_fail("这里只能淬炼(cuilian)神兵(weapon)!\n");

 if(  !objectp(wpn = me->query_temp("weapon") ))
        return notify_fail("你没有随身携带武器，单靠读书是无法理解的。\n");    

     wpn = me->query_temp("weapon");

if(wpn->query("maker")=="韦兰铁匠(Weilan tiejiang)") 
          return notify_fail(HIR"\n你试着将真气灌注到"+wpn->query("weapon_mp/name")+""HIR"中。。。。\n"HIG"你沮丧的发现，"+wpn->query("weapon_mp/name")+""HIG"未曾经历过龙潭血祭，无法经受你的真气淬制。\n\n"NOR);

     if (me->is_busy() || me->is_fighting()|| me->query_temp("con_weapon") )
       return notify_fail("你正忙着呢。\n");

 if (me->query_temp("canwu_now") )
       return notify_fail("你正忙着呢。\n");
       
       if (query_temp("canwu") )
       return notify_fail("有人正在参悟呢，你等一会把。\n");

     if( me->query("combat_exp",1)<10000000)
         
        return notify_fail("你胡乱的翻了翻书架上的藏书，发现里面的内容高深莫测，无法理解，不由得摇了摇头。\n");

       

     if(wpn->query("id")=="songwen jian")
   
              return notify_fail("你发现这松纹古剑灵气盎然，天生璞质，根本用不着淬炼。\n");

     if( wpn->query("weapon_mp/owner",1)!= me->query("id") )   
          return notify_fail("这并不是你自己的私人武器，你何苦花大力气去淬制养护呢。\n");

// if ( wpn->query("weapon_mp/weapon_prop/damage",1)      >=300
if(  wpn->query("weapon_mp/weapon_prop/attack",1)      >=150
|| wpn->query("weapon_mp/weapon_prop/dexerity",1)     >=20
|| wpn->query("weapon_mp/weapon_prop/constitution",1) >=20
|| wpn->query("weapon_mp/weapon_prop/intelligence",1) >=20
|| wpn->query("weapon_mp/weapon_prop/strength",1)     >=20 )

                 return notify_fail("你手中乃是当世数一数二的神兵，自有灵性，根本不需要再加淬制了。。\n");

       message_vision( HIW"$N仔细的翻看着书架上的藏书，对里面如何淬养神兵的内容很感兴趣。\n"NOR,me);
       message_vision( HIW"$N一头扎进书堆里.不停的翻看着。。 \n"NOR, me);
  
       me->start_busy(100);  
       me->set_temp("canwu_now",1); 
       set_temp("canwu",1);            
     call_out("thinking",5, me );
         return 1;

 }

int thinking(object me)
{
 int d,a,dexe,cons,inte,stre,t,cj,max_cj,yd,fld,exp,temp;
  object wpn;
  wpn = me->query_temp("weapon");
  if(!me) return 0;
	
  if(me->query_temp("con_weapon")<(3+random(3)))
       {  me->add_temp("con_weapon",1);
          if(random(2)) tell_object(me,HIG"\n你仔细的研读着书里面的内容，只觉得耳目一新...\n"NOR);
                   else tell_object(me,HIY"\n你参照着书中所记载的内容，慢慢的将真气输入到武器之中...\n"NOR);  

	  tell_room(environment(me),HIC""+me->query("name")+"默运玄功，手中"+wpn->query("weapon_mp/name")+""HIC"慢慢的泛出一道奇异的光辉...\n"NOR, ({}));

	  remove_call_out("thinking");
	  call_out("thinking",3+random(3), me);

	}

 else { 
         me->delete_temp("con_weapon");
         me->start_busy(1);     
  message_vision(HIC"\n$N手中"+wpn->query("weapon_mp/name")+""HIR"忽做龙吟，似乎增加了不少灵性！”\n"NOR,me); 
  
     tell_object(me,HIR"\n你对"+wpn->query("weapon_mp/name")+""HIR"成功的进行了一次淬炼！\n"NOR);
       me->add("combat_exp",-500000);
temp=5+random(5);
   wpn->add("weapon_mp/weapon_prop/damage",temp) ;
       if(wpn->query("weapon_mp/weapon_prop/damage",1) >300)  
          wpn->set("weapon_mp/weapon_prop/damage",300) ;
temp=3+random(2);
   wpn->add("weapon_mp/weapon_prop/attack",temp);
       if(wpn->query("weapon_mp/weapon_prop/attack",1) >150)
          wpn->set("weapon_mp/weapon_prop/attack",150);
temp=random(5);
 if(temp>=3)   wpn->add("weapon_mp/weapon_prop/dexerity",1);
       if( wpn->query("weapon_mp/weapon_prop/dexerity",1)>20)
          wpn->set("weapon_mp/weapon_prop/dexerity",20);


temp=random(5);
 if(temp>=3)    wpn->add("weapon_mp/weapon_prop/constitution",1);
       if( wpn->query("weapon_mp/weapon_prop/constitution",1)>20)
          wpn->set("weapon_mp/weapon_prop/constitution",20);
temp=random(5);
 if(temp>=3) 
   wpn->add("weapon_mp/weapon_prop/intelligence",1);
       if( wpn->query("weapon_mp/weapon_prop/intelligence",1)>20)
          wpn->set("weapon_mp/weapon_prop/intelligence",20);
temp=random(5);
 if(temp>=3) 
   wpn->add("weapon_mp/weapon_prop/strength",1) ;   
      if( wpn->query("weapon_mp/weapon_prop/strength",1)>20)
          wpn->set("weapon_mp/weapon_prop/strength",20);
   wpn->add("weapon_mp/dur",10000) ;   
   wpn->add("weapon_mp/max_dur",10000) ;   
   wpn->add("dur",10000) ;   
   wpn->add("max_dur",10000) ;   
   wpn->add("sharpness",1) ;   
   wpn->add("weapon_mp/sharpness",1) ;   
   wpn->add("weapon_mp/rigidity",1) ;   
   wpn->add("rigidity",1) ;   


d= wpn->query("weapon_mp/weapon_prop/damage",1);
a= wpn->query("weapon_mp/weapon_prop/attack",1);
dexe= wpn->query("weapon_mp/weapon_prop/dexerity",1);
cons= wpn->query("weapon_mp/weapon_prop/constitution",1);
inte= wpn->query("weapon_mp/weapon_prop/intelligence",1);
stre= wpn->query("weapon_mp/weapon_prop/strength",1) ;   
cj=wpn->query("weapon_mp/dur",1);
max_cj=wpn->query("weapon_mp/max_dur",1);
yd=wpn->query("weapon_mp/rigidity",1);
fld=wpn->query("weapon_mp/sharpness",1);
    me->add("relife/weapon",1); 
    t= me->query("relife/weapon",1);
    me->delete_temp("canwu_now");   
    delete_temp("canwu");   

    tell_object(me,HBBLU"\n你本次淬炼共耗费了五百万实战经验，你的"+wpn->query("weapon_mp/name")+""HBYEL"属性提升为：\n"NOR);
    tell_object(me,HIM"\n持久提升一万点，目前为【"+HIW+chinese_number(cj)+NOR+"】【"+HIC+chinese_number(max_cj)+NOR+"】。\n"NOR);
    tell_object(me,HBRED"硬度："+HIR+chinese_number(yd)+HIG+"，锋利度"+HIW+chinese_number(fld)+NOR+"，\n"NOR);
    tell_object(me,HBMAG"威力："+HIR+chinese_number(d)+HIR+"，命中"+HIW+chinese_number(a)+HIW+"，\n"NOR);
   tell_object(me,"增加膂力"+HIG+chinese_number(stre)+NOR+"点，身法"+HIM+chinese_number(dexe)+NOR+"点，根骨"+HIC+chinese_number(cons)+NOR+"点，悟性"+HIY+chinese_number(inte)+NOR+"点。\n"NOR);


      log_file("canwu/getexp", sprintf("%s(%s) 第%d次参悟淬炼武器部分，武器威力%d，命中%d，力%d身%d根%d悟%d， 当前经验：%d。\n", 
       me->name(1),
       me->query("id"),
       t,
       d,
       a,
       stre,  
       dexe,
       cons,
       inte,
       me->query("combat_exp")) );
  
   }

}
