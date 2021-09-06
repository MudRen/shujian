// Room: tianhu.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һƬ�����ĵ�ˮ�������һ�����󣬺�ˮ�峺տ�������ֳ�һ������
�ĸ�ԭ��⡣
���ǣ�
    ����ŭ����ˣ������չ⺮��
    �޷�ˮ�����������������ƣ�΢������������ɳ���Ӱ��ɡ�
    һǧ�������£�ֻ��̲���ƾ�ʱ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu1",
                "south" : __DIR__"xiaodian",
                "southwest" : __DIR__"xiaolu1",
"north" :__DIR__"tianxi",
	]));
        set("outdoors", "ѩɽ");
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
return notify_fail("���������Ұѵ����ɣ�\n");
if (me->query("family/master_name") != "Ѫ������")
 return notify_fail("�㲻��Ѫ���ŵ��ӣ���Ҫ������\n");

if(!me->query_temp("quest/ѩɽ/shendao/jidao/asklaozu"))
return notify_fail("��Ҫ��ʲô!\n");



     if (me->is_busy() || me->is_fighting()|| me->query_temp("jidao") )
                  return notify_fail("����æ���ء�\n");


     if( me->query("combat_exp",1)<2000000)
                 return notify_fail("�����Ϊ��������ʱ���������˼�����\n");
if (!night)
return notify_fail("����Ҫ������ҹ��ʱ�ַ��ɡ�\n");
if( me->query("quest/ѩɽ/shendao/jidao") )
return notify_fail("���Ѿ���Ѫ�����ɹ��ˣ�����Ҫ�ټ��ˡ�\n");

message_vision( HIR"$N���������������Ȼ��˵������Ϊ�Ҳ�֪��ô��\n"NOR,me);
       message_vision( HIR"$Ņͷ��������һ�����£�����ҹ���˾�֮ʱ�����䱦�������������죬ԭ����������Ѫ�ˡ�\n"NOR,me);
        message_vision( HIR"$N��æ�γ�������ҧҧ���ݺ������Լ��۲�֮�Ϸ�����ȥ������������Ѫ��������һ�㱥�������� \n"NOR, me);
message_vision( HIW"$N�������վ�������Ȼ��������̼䲼��ȫ���澭������ \n"NOR, me);

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
          tell_object(me,HIR"\n����ס��ʹ���˷ܵؿ������б���ʹ���Լ�����Ѫ...\n"NOR);
           tell_object(me,HIY"\n��������֮�����ϣ��ƺ���δ����...\n"NOR);  
         tell_object(me,HIW"\n�㰵���߶����վ��ڹ����ƺ���������...\n"NOR);  
          tell_room(environment(me),HIC""+me->query("name")+"üͷ���壬�ƺ��������ž޴�ʹ��...\n"NOR, ({}));
}
          remove_call_out("thinking");
          call_out("thinking",3+random(3), me);

        }
else
{
me->delete_temp("jidao");
tell_object(me,HIR"\n����ʹ���˰��Σ�����ط���һ�����죬����������Ⱦ���ʺ��Ѫɫ��\n"NOR);
 message_vision(HIC"\n$N������������Ц������˵������������������������ɽɱ�ˣ���\n"NOR,me); 
tell_object(me,HIR"�����ж����������Ҫ��ɽɱ���Ե���\n"NOR);
me->add("shen",-100000);
me->delete_temp("quest/ѩɽ/shendao/jidao/asklaozu");
me->set("quest/ѩɽ/shendao/jidao",1); 
me->start_busy(1);
}
}
