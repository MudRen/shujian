// mr up_uweapon_feature.c
// be jpei 2010

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short",HIG"娘缳玉洞-装备部"NOR);
	
        set ("long",@long
这是曼佗罗山庄精炼特殊装备的地方，玩家可以在此精炼(jinglian)装备，
精炼时请务必输入装备全部拼音。
long);
	set("exits",([
		"out" : __DIR__"huandong",
	]));


	set("no_fight", 1);
	setup();
}


void init()
 {
         add_action("do_canwu", "jinglian");
 }



int do_canwu(string arg)
 {
     object me = this_player();
     object wpn;
         if(!arg)
           return notify_fail("你要精练什么？\n");

 
switch(arg){
                case "yongzhe zhanpao":
                case "langya zhanpao":
                break;
                case "langya zhanxue":
                case "yongzhe zhanxue":
                break;
                case "langya huyao":
                case "yongzhe huyao":
                break;
                case "langya shoutao":
                case "yongzhe shoutao":
                break;
                case "langya huwan":
                case "yongzhe huwan":
                break;
                case "langya toukui":
                case "yongzhe toukui":
                break;
                case "langya dunpai":
                case "yongzhe dunpai":
                break;
                case "langya pifeng":
                case "yongzhe pifeng":
                break;
                                default:
                        return notify_fail("这里不能精炼这种装备。\n");
        }


wpn = me->query_temp("armor/"+arg);
if(!objectp(wpn = present(arg, me)))       
 return notify_fail("你没有随身携带装备，精炼什么。\n");    
     if (me->is_busy() || me->is_fighting() )
       return notify_fail("你正忙着呢。\n");

 if (me->query_temp("canwu_now") )
       return notify_fail("你正忙着呢。\n");
       
       if (query_temp("canwu") )
       return notify_fail("有人正在精炼呢，你等一会把。\n");

     if( me->query("combat_exp",1)<2000000)
         
        return notify_fail("你的经验不够，根本没法精炼。\n");

 if( !wpn->query("canjinglian"))   
          return notify_fail("这种东西没法精炼。\n");  






     

   if ( wpn->query("armor_prop/damage",1)      >=300
    && wpn->query("armor_prop/attack",1)      >=100
    && wpn->query("armor_prop/dexerity",1)     >=20
    && wpn->query("armor_prop/constitution",1) >=20
    && wpn->query("armor_prop/intelligence",1) >=20
&& wpn->query("armor_prop/strength",1)     >=20 || me->query("jinglian/"+arg) == 9)

return notify_fail("你的装备已是精品，自有灵性，根本不需要再加精炼了。。\n");

message_vision( HIW"$N将"+wpn->query("name")+""HIW"放在精炼池中准备精炼。\n"NOR,me);
message_vision( HIW"$N专心致志地，将"+wpn->query("name")+""HIW"仔细炼制。\n"NOR, me);
  
       me->start_busy(100);  
       me->set_temp("canwu_now",1); 
       set_temp("canwu",1);            
call_out("thinking",5, me, wpn ,arg );
         return 1;

 }

int thinking(object me,object wpn,string arg)
{
 int d,a,dexe,cons,inte,stre,t;
object ob1,ob2;
    if(!me) return 0;

	
  if(me->query_temp("con_weapon")<(3+random(3)))
       {  me->add_temp("con_weapon",1);
if(random(2)) tell_object(me,HIG"\n你仔细的精炼着...\n"NOR,me);
                   else tell_object(me,HIY"\n你慢慢的将真气输入到装备之中...\n"NOR,me,wpn);  

tell_room(environment(me),HIC""+me->query("name")+"默运玄功，手中装备慢慢的泛出一道奇异的光辉...\n"NOR, ({}));

	  remove_call_out("thinking");
call_out("thinking",3+random(3), me,wpn,arg);

	}

 else { 
         me->delete_temp("con_weapon");
         me->start_busy(1); 


ob1 = present("shensheng zhufu", me);

if (ob1 || me->query("jinglian/"+arg) < 3
|| me->query("jinglian/"+arg) == 4 && random(100) > 40
|| me->query("jinglian/"+arg) == 5 && random(100) > 50 
|| me->query("jinglian/"+arg) == 6 && random(100) > 60
|| me->query("jinglian/"+arg) == 7 && random(100) > 70 
|| me->query("jinglian/"+arg) == 8 && random(100) > 80)

 {    
message_vision(HIC"\n$N手中装备忽做龙吟，似乎增加了不少灵性！”\n"NOR,me); 
  
     tell_object(me,HIR"\n你对目前装备成功的进行了一次淬炼，属性在下次登录时生效！\n"NOR,me,wpn);
       me->add("combat_exp",-200000);

   me->add("jinglian/"+arg,1);

d= wpn->query("armor_prop/damage",1);
a= wpn->query("armor_prop/attack",1);
dexe= wpn->query("armor_prop/dexerity",1);
cons= wpn->query("armor_prop/constitution",1);
inte= wpn->query("armor_prop/intelligence",1);
stre= wpn->query("armor_prop/strength",1) ;   

    me->add("relife/weapon",1); 
    t= me->query("relife/weapon",1);
    me->delete_temp("canwu_now");   
    delete_temp("canwu");   
destruct(ob1);

    tell_object(me,HBYEL"\n你本次精炼共耗费了二十万万实战经验！\n"NOR,me);
    tell_object(me,"威力："+HIR+chinese_number(d)+HIR+"，命中"+HIW+chinese_number(a)+HIW+"，\n"NOR);
   tell_object(me,"增加膂力"+HIG+chinese_number(stre)+NOR+"点，身法"+HIM+chinese_number(dexe)+NOR+"点，根骨"+HIC+chinese_number(cons)+NOR+"点，悟性"+HIY+chinese_number(inte)+NOR+"点。\n"NOR);


      log_file("quest/jinglian", sprintf("%s(%s) 第%d次参悟淬炼武器部分，武器威力%d，命中%d，力%d身%d根%d悟%d， 当前星级：%d。\n", 
       me->name(1),
       me->query("id"),
       t,
       d,
       a,
       stre,  
       dexe,
       cons,
       inte,
       me->query("jinglian/"+arg)) );
  
   }
ob2= present("wanbi fu", me);
if (ob2)
{
message_vision(HIG"\n$N因为手中有完璧符，虽精炼失败，但保存了装备的完整。\n"NOR,me);
tell_object(me,HIR"\n你的装备在本次精炼中无效！\n"NOR);
me->add("jinglian/"+arg,-1);
me->delete_temp("canwu_now");
delete_temp("canwu"); 
destruct(ob2);
log_file("quest/jinglian", sprintf("%s(%s) 使用完璧符，装备星级%d。\n", me->name(1),me->query("id"),me->query("jinglian/"+arg)+1));
}
else 
{
 message_vision(HIC"\n$N手中装备禁不起这激烈的震荡，竟然破碎了！”\n"NOR,me); 
tell_object(me,HIR"\n你的装备在精炼中损坏了！\n"NOR);
me->add("jinglian/"+arg,-1);
 me->delete_temp("canwu_now");   
    delete_temp("canwu");   

wpn->move(environment(me));
wpn->set("name", "破碎的" + wpn->query("name"));
wpn->set("value", 0);
  wpn->set("armor_prop", 0);
log_file("quest/jinglian", sprintf("%s(%s) 精炼坏了，装备星级%d。\n", me->name(1),me->query("id"),me->query("jinglian/"+arg)+1));

}
}
}
