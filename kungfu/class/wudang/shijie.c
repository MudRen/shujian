#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "石阶");
        set("long", @LONG
松林渐渐开阔，面前出现了一条宽广的石板道，笔直通向前方。沿道稀
稀落落地种着几棵柏树，却显得高大挺拔，蝤龙般的枝干向天空高高伸展着
。你来到此间，不禁四处张望(zhangwang)，想找些线索出来。
想要离开就赶紧离开吧(leave)。
LONG
        );

 set("outdoors", "shaolin");    
set("no_fight", 1);
   set("exits", ([
                 "leave" : "/d/wudang/houyuan",
]));
   setup();
}
void init()
{
	add_action("do_zhangwang","zhangwang");
}
int do_zhangwang()
{
	object me = this_player();
	
	if( (int)me->is_busy() || me->is_fighting()) 
		return notify_fail("你正忙着呢。\n");
        if(!me->query_temp("wdjiuyang1"))
               return notify_fail("你怎么来到这里的？\n");
tell_object(me,WHT"你手搭凉棚，伸长脖子四处张望，却不知从哪里涌出一队僧兵。\n"NOR); 
tell_object(me,WHT"为首的是一个面色严厉的老僧，只听那老僧喝令众僧兵道：\n"
                  HIR"\n“达摩堂众弟子一齐上前，把这小厮拿下了。”\n"NOR);

remove_call_out("meet");
call_out("meet", 2);
me->delete_temp("wdjiuyang1");
return 1;
}
int meet(object me)
{
me = this_player();
tell_object(me,WHT"\n你当下大骇，心想：我犯了什么罪过，招来如此大祸？\n"NOR);   
tell_object(me,WHT"达摩堂不是少林所在么？自己如何又跑到少林去了？\n"NOR);  
tell_object(me,WHT"\n正在不知所措之中，那达摩堂与罗汉堂众弟子登时抢出，已将\n"
                  "一名老僧、一名少年和一名少女围在中间。那少年手足无措,\n"
                 "说道：“师父，我……我……”\n"NOR);
tell_object(me,HIR"\n但听那严厉老僧喝道：“还不动手，更待何时！”\n"NOR);   
remove_call_out("meet1");
        call_out("meet1", 2, me);
        return 1;
}
int meet1(object me)
{
me = this_player();
tell_object(me,HIG"\n你见原来并不是要拿下你，心中稍宽，却走也不是留也不是。\n"NOR);  
tell_object(me,WHT"\n那被围的老僧不暇思索，蓦地里转了个圈子，用两只大铁桶舞了\n"
                    "开来，一般劲风逼得众僧不能上前，跟着挥桶一抖，桶中清水都\n"
                    "泼了出来，侧过双桶左边铁桶兜起那少女，右边铁桶兜起你，连\n"
                    "转七八个圈子，那对大铁桶给他浑厚无比的内力使将开来，犹如\n"
                    "流星锤一般，这股千斤之力天下谁能挡得？达摩堂众弟子纷纷闪避。\n"NOR);

remove_call_out("meet2");
        call_out("meet2", 2, me);
        return 1;
}
int meet2(object me)
{
me = this_player();
tell_object(me,HIG"\n他本意乃是挑起这小女和那瘦弱少年，谁知慌乱之间挑错了人，\n"
                    "将你挑在了捅中却浑然不觉，你也心中焦急想出声告诉他，无奈\n"
                    "那老僧健步如飞，身法急快，你只觉耳边风声呼啸，想张嘴出声\n"
                    "却难上加难，只得随他去了......\n"NOR); 
  me->set_temp("wdjiuyang2",1);
me->move("kungfu/class/wudang/shenshan");
        return 1;
}
