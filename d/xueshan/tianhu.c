// Room: tianhu.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "天湖");
	set("long", @LONG
这里是一片广阔的淡水湖，天空一望无垠，湖水清澈湛蓝，呈现出一幅独特
的高原风光。
真是：
    长风怒卷高浪，飞洒日光寒，
    无风水面琉璃滑，不觉船移，微动涟漪，惊起沙禽掠岸飞。
    一千五百年间事，只有滩声似旧时。
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu1",
                "south" : __DIR__"xiaodian",
                "southwest" : __DIR__"xiaolu1",
"north" :__DIR__"tianxi",
	]));
        set("outdoors", "雪山");
        set("objects", ([
  			       __DIR__"npc/zhimaya" : 1,
     			       __DIR__"npc/bantouyan" : 1
        ]));
	set("coor/x",-250);
  set("coor/y",140);
   set("coor/z",0);
   setup();
}

void init()
 {
         add_action("do_jidao", "jidao");
          }

int do_jidao()
 {
int time, night;
object me = this_player();
object weapon;
   mixed *local; 
night = 0;
local = localtime(time() * 60);
if (local[2] < 5 || local[2] >= 19) night = 1;
     

if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "blade")
return notify_fail("你起码先找把刀来吧？\n");
if (me->query("family/master_name") != "血刀老祖")
 return notify_fail("你不是血刀门弟子，不要乱来。\n");

if(!me->query_temp("quest/雪山/shendao/jidao/asklaozu"))
return notify_fail("你要干什么!\n");



     if (me->is_busy() || me->is_fighting()|| me->query_temp("jidao") )
                  return notify_fail("你正忙着呢。\n");


     if( me->query("combat_exp",1)<2000000)
                 return notify_fail("你的修为不够，此时祭刀恐怕伤及自身。\n");
if (!night)
return notify_fail("祭刀要到晚上夜深时分方可。\n");
if( me->query("quest/雪山/shendao/jidao") )
return notify_fail("你已经鲜血祭刀成功了，不需要再祭了。\n");

message_vision( HIR"$N心中想道：老贼虽然不说，但以为我不知晓么？\n"NOR,me);
       message_vision( HIR"$N抬头看看天上一轮明月，正是夜深人静之时，腰间宝刀竟自嗡嗡作响，原来是欲饮人血了。\n"NOR,me);
        message_vision( HIR"$N连忙拔出宝刀，咬咬牙狠狠心向自己臂膊之上奋力砍去，宝刀见到鲜血竟似有灵一般饱饮起来。 \n"NOR, me);
message_vision( HIW"$N体内神照经真气自然激荡，顷刻间布满全身奇经八脉。 \n"NOR, me);

       me->start_busy(100);    
       me->receive_wound("qi", 800+random(200), me);
                   call_out("thinking",3, me );
         return 1;

 }
int thinking(object me)
{
  int i,j,p;
  if(!me) return 0;
        
  if(me->query_temp("jidao")<(3+random(3)))
 
       {  
me->add_temp("jidao",1);
if (random(3)) 
{
          tell_object(me,HIR"\n你忍住疼痛，兴奋地看着手中宝刀痛饮自己的鲜血...\n"NOR);
           tell_object(me,HIY"\n宝刀嗡嗡之声不断，似乎还未满足...\n"NOR);  
         tell_object(me,HIW"\n你暗暗催动神照经内功，似乎心有所得...\n"NOR);  
          tell_room(environment(me),HIC""+me->query("name")+"眉头紧皱，似乎在忍受着巨大痛苦...\n"NOR, ({}));
}
          remove_call_out("thinking");
          call_out("thinking",3+random(3), me);

        }
else
{
me->delete_temp("jidao");
tell_object(me,HIR"\n宝刀痛饮了半晌，“铮”地发出一声脆响，整个刀身都浸染了鲜红的血色。\n"NOR);
 message_vision(HIC"\n$N「哈哈哈」大笑几声，说道：“宝刀宝刀，快随我下山杀人！”\n"NOR,me); 
tell_object(me,HIR"你心中恶念顿生，就要下山杀人试刀。\n"NOR);
me->add("shen",-100000);
me->delete_temp("quest/雪山/shendao/jidao/asklaozu");
me->set("quest/雪山/shendao/jidao",1); 
me->start_busy(1);
}
}
