// rape.c
// by hongba
#include <ansi.h>
void post(object me, object obj);
void sec_post(object me, object obj);
void trd_post(object me, object obj);
void over(object me, object obj);
void over1(object me, object obj);


int main(object me, string arg)
{
	object obj, *ob,where;
	int i;
if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");

	if ( !arg || !objectp(obj = present(arg, environment(me)))) return notify_fail("你想“办理”谁？\n");

	if ( !obj->is_character() || me->query("gender") == obj->query("gender") || obj->query("race")=="野兽" )
		return notify_fail("这玩意你都想上？口味够重啊？\n");

	if ( !living(obj)) return notify_fail("人家都这样了，你还...\n");

	
	if ( me->query("gender") == "女性" && me->query_condition("pregnant") )
		return notify_fail ("你是个女人呀，怎么如此大方？\n");

	if ( obj->query("gender") == "女性" && obj->query_condition("pregnant") )
		return notify_fail ("人家已经怀孕了，还要……？你可够残忍的\n");

		if ( (int)me->query("age", 1) < 18 ) return notify_fail ("小鸡巴孩子滚远点！\n");
if( me->query("gender") =="无性" )
                return notify_fail("你一个死太监，也来弄这调调？\n");


	if ( (int)obj->query("age", 1) < 18 ) return notify_fail ("欺负那么小的孩子，臭不要脸，遭雷劈！\n");
if( obj->query("raped") > 5) 
return notify_fail ("这个女人都烂了，你也想上！\n");
// 被强奸多于5次就饶了人家吧

	
	where=environment(me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++)
		if( ob[i]->is_character()&&ob[i] != me && ob[i]!=obj&&!wizardp(ob[i]) )
			return notify_fail("光天化日，朗朗乾坤，那么多人在，你就不怕王法？\n");

				message_vision(HIC "$N悄悄窜至$n身后，突然将$n紧紧搂住，\n" +
				"在$n耳边凶狠地说道：小乖乖，让大爷爽爽……\n"NOR, me, obj);
CHANNEL_D->do_channel( this_object(), "rumor", sprintf("%s(%s)在%s正在强暴%s，有人管没人管？？？\n",
			me->name(1),getuid(me),(string)where->query("short"),obj->name(1)			
			));

me->start_busy(999);
obj->start_busy(999);

						call_out("post", 3, me, obj);
return 1;
}

void post(object me, object obj)
{
	message_vision(HIC"\n$n转身就要开溜，被$N一把拦住。\n"NOR,me,obj);
message_vision(HIC"\n看来$n被$N紧紧抱住，没了力气，只有任$N宰割了。\n"NOR,me,obj);


	call_out("sec_post", 3, me, obj);
}

void sec_post(object me, object obj)
{
	message_vision(HIC"\n由于近在咫尺，$N又忍不住仔细端详了$n一下。\n"NOR, me, obj);
message_vision(HIC"\n$N望了望附近，看了看，没人注意，不由的.....。\n"NOR, me, obj);

	call_out("trd_post", 4, me, obj);
}

void trd_post(object me, object obj)
{
	message_vision(HIW"\n好一会儿,$N再也按赖不住心中的欲火，将$n身上的衣物一件一件地扯下。\n\n"NOR, me, obj);
if(obj->query("marry/id") ){
message_vision(HIY"\n虽说已不再是处女,但身为少妇的$n那丰满的身体曲线也让你垂涎三尺!\n"NOR, me, obj);
message_vision(HIC"\n接着$N一把将$n按倒在地上。。。。。\n"NOR, me, obj);
message_vision(HIC"\n四周充斥着$N那野兽般的吼叫声和$n撕心裂肺的哭声。。。\n"NOR, me, obj);

call_out("over", 3, me, obj);
}

else {
message_vision(HIM"\n$n身上那阵阵处女体香，撩拨得$N垂涎三尺，再也等待不及！\n"NOR, me, obj);
message_vision(HIC"\n接着$N一把将$n按倒在地上。。。。。\n"NOR, me, obj);
message_vision(HIC"\n四周充斥着$N那野兽般的吼叫声和$n撕心裂肺的哭声。。。\n"NOR, me, obj);

call_out("over", 4, me, obj);

}

	
}

void over(object me, object obj)
{
       	message_vision(HIR"良久，风停雨歇。。。。。\n"NOR, me,obj);
if(obj->query("marry/id") || obj->query("raped") ){
message_vision(HIY"\n$N爬了起来，对着昏睡在地的$n失望地叹了一下气：真他妈的倒霉,让老子遇到这种'水货'。\n"NOR, me, obj);
message_vision(HIC"\n这时只见$N摇摇晃晃，立足不稳。\n"NOR, me, obj);
message_vision(HIC"\n原来你发现自己全身乏力，看来是虚耗过度了！

\n\n"NOR, me, obj);
}
else {
message_vision(HIG"\n$N爬了起来，对着昏睡在地的$n美美地叫道：嘿嘿，还是个黄花闺女，让老子捡了个大便宜。\n"NOR, me, obj);
message_vision(HIC"\n这时只见$N摇摇晃晃，立足不稳。\n"NOR, me, obj);
message_vision(HIC"\n原来$N发现自己全身乏力，看来是虚耗过度了！\n"NOR, me, obj);
me->add("jing",-1000);
}

CHANNEL_D->do_channel(this_object(), "rumor", obj->name(1)+"被" 
	    + me->name(1)+"在"+environment(me)->query("short")
	    + "强暴了!");
CHANNEL_D->do_channel(this_object(), "rumor", me->name(1)+"被官府通缉！" 
	    );


me->apply_condition("killer",500); 


call_out("over1", 3, me, obj);

}
void over1(object me, object obj)
{
/*
 message_vision(HIR"\n$n慢慢地爬了起来，满面泪痕地对着$N大喝一声:"+me->query("rank_info/rude")+"休逃，你污我身体，让我怎生作人,
索性和你拼了！\n"NOR, me, obj);
*/
message_vision(HIR"\n$n慢慢地爬了起来，满面泪痕地对着$N大喝一声:禽兽休逃，你污我身体，让我怎生作人,索性和你拼了！\n"NOR, me, obj);
obj->add("raped",1);  // 被强奸的次数
me->start_busy(10);
obj->start_busy(4);
obj->kill_ob(me);
me->fight_ob(obj);
}




	
int help(object me)
{
	write(@HELP
指令格式 : rape <人物>
江湖中无风不起浪,武侠的世界里总是少不了采花贼的，
象金庸先生笔下的田伯光等,这个命令正是留给他们的.
但当采花贼不仅对修为不利,而且还要面对满街的讨打声，
没有一点真本事,可有点受不了。
有道是'多行不义必自毙'，用之者慎之！慎之！
当然正人君子莫为之！
HELP);
	return 1;
}
