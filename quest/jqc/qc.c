#include <ansi.h>
inherit ITEM;
#define TASKREWARD_D "adm/daemons/jobrewardd"
void create()
{
        set_name(HIR"囚车"NOR, ({"qiu che","che"}));
        set("unit", "辆");
        set("long", "这是一辆押解犯人的囚车，上面囚禁着一位反清志士。\n");
        set("value", 0);
        set("no_get",1);
    set("location",1);
//上面应该是刷新周期吧
        setup();
}

void init()
{
  	
  	add_action("do_jie", "jie");
       add_action("do_save", "jiu");

}
int do_jie(string arg)
{
	object me=this_player() , ob , bb;

	if (!arg) return notify_fail("你要劫什么？\n");

if (!me->query("jn/qiuche"))
return notify_fail("你没事吧？这可是谋反的罪过啊！\n");	
if (me->query_temp("jn/jie"))
return notify_fail("你劫囚车成功了，还不救人？\n");

message_vision(HIC"$N"HIC"一时豪气迸发，径直上前高喊：“朝廷的鹰爪孙们，识相的快将车上人放了！\n"NOR,me, ob);
message_vision(HIC"\n四下护卫囚车之人一愣，均想：此人有病吧？\n"
"虽是做如此之想，手下并不怠慢，纷纷上前，将$N围在当下。\n",me,ob);
me->set_temp("jn/jie",1);
bb = new("quest/jqc/guard");
bb->do_copy(me,0);
bb->move(environment(me));
me->kill_ob(bb);
bb->kill_ob(me);
bb = new("quest/jqc/guard");
bb->do_copy(me,0);
bb->move(environment(me));
me->kill_ob(bb);
bb->kill_ob(me);
bb = new("quest/jqc/guard");
bb->do_copy(me,0);
bb->move(environment(me));
me->kill_ob(bb);
bb->kill_ob(me);

return 1;
}
int do_save(string arg)
{
object me=this_player() , ob,bb;
if (arg!= "人") 
return notify_fail("你要救什么？\n");
if (!me->query("jn/qiuche") || !me->query_temp("jn/jie")) 
return notify_fail("你没事吧!!!这可是谋反的罪过啊！\n");	
if(present("gao shou"))
return notify_fail("清廷鹰犬还在，你怎么救人？\n");
if(me->is_fighting()) return notify_fail("战斗中腾不出空来救人。\n");
TASKREWARD_D->get_reward(me,"劫囚车",1,0,0,20,0,0,0,this_object());
message_vision(HIC"$N"HIC"快步上前砸开囚车，将车内的人救了出来。\n"NOR,me, ob);
message_vision(HIC"\n反清志士对着$N抱拳一礼，说道：“待到大事告成之后，\n"
"再来把酒言欢！”说罢便匆匆离去。\n",me,ob);
me->delete("jn/qiuche");
me->delete("jn/time");
me->delete_temp("jn/bb");
me->delete_temp("jn/jie");
me->set("job_name","劫囚车");
destruct(this_object());
me->delete("jn/qiuche_ob");
me->delete("jn/qiuche_super");
me->apply_condition("jn_job",40);
me->apply_condition("job_busy",1);
return 1;
}



void dest()
{
        write(HIW"囚车缓缓地在大内高手的护卫下离开了。\n"NOR);
	destruct(this_object());
}
