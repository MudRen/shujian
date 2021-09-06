// 对穿肠，娱乐项目
// by hongba

inherit NPC;
#include <ansi.h>

int ask_duilian(string arg);
void init()
{
        add_action("do_guess", "answer");
}

void create()
{
 set_name(HIC"对穿肠"NOR, ({"dui chuanchang", "dui", "chuanchang" }) );
set("title", BRED HIW"对遍天下无敌手"NOR);

        set("gender", "男性" );
        set("age", 60+random(10));
        set("long", HIW"他是个饱读诗书的老先生，擅长对对联。你可以(ask dui about 对对联)。
然后用(answer)来回答下联。\n"NOR);

       set("inquiry", ([
 "对对联"          : (: ask_duilian :),
 ]));


	setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}




int ask_duilian(string arg)
{
object me;
string answer;
me = this_player();
if (!me)
return 0;

if (me->query_temp("askduilian"))
{
 command("say 你先把这个对了再说吧");
return 1;
}
switch (random(17)) {
		case 0:
			command("say 龙腾华夏金鼙壮?");
			me->set_temp("answer","春暖虞唐草木荣");
			break;
		case 1:
			command("say 龙腾霄汉开新运?");
			me->set_temp("answer","鹊立枝头报好音");
			break;
		case 2:
			command("say 万水千山凭虎跃？");
			me->set_temp("answer","五湖四海任龙腾");
			break;
		case 3:
			command("say 喜兔岁九州丰稔？");
me->set_temp("answer","愿龙年百业昌荣");
			
			break;
		case 4:
			command("say 欣闻禹域鸣雏凤？");
me->set_temp("answer","喜看神州起卧龙");
			
			break;
		case 5:
			command("say 紫燕飞来寻玉兔？");
me->set_temp("answer","黄鹂唱起戏金龙");
			answer = "黄鹂唱起戏金龙";
			break;
		case 6:
			command("say 金龙贺喜出东海？");
me->set_temp("answer","玉兔辞岁回月宫");
			
			break;
		case 7:
			command("say 喜谢玉兔留宝在？");
me->set_temp("answer","笑迎金龙常春来");
			
			break;
		case 8:
			command("say 玉龙吐宝千重瑞？");
me->set_temp("answer","金莺报喜四时宁");
			
			break;


case 9:
			command("say 白马嘶风，紫衣迭影，回疆万里沙来，几曾想银鞭我？");
me->set_temp("answer","青灯如豆，古井不波，北地千山路转，但惟余玉凤从君");
			
			break;

case 10:
			command("say 侬声语软，燕子低回，半湖水，绿归兰桨？");
me->set_temp("answer","珠泪痕残，菱花清减，一段痴，缘系竹篮");
			
			break;

case 11:
			command("say 断右臂如何，疏狂不改。九千仞重阳，凭谁试剑？");
me->set_temp("answer","负红颜几许，至性依然。十六年绝谷，为我消魂");
			
			break;
case 11:
			command("say 风陵渡，襄阳城，一夜烟花一夜雪？");
me->set_temp("answer","太华巅，峨嵋顶，半轮枕月半轮秋");
			
			break;
case 12:
			command("say 宁不愧男儿，便尔等门辖六派，安得倚天裁宝剑？");
me->set_temp("answer","真羞惭诸女，纵张郎手易乾坤，也须执笔画娥眉");
			
			break;
case 13:
			command("say 大小通吃，何须七美排名次？");
me->set_temp("answer","仙福永享，笑煞中原逐鹿人");
		
			break;
case 14:
			command("say 说什么风临玉树，霸业王图，成，不外是：千嶂烽烟，野哭白骨？");
me->set_temp("answer","徒感伤斗转星移，惊才绝羡，败，只嬴得：半山落日，一统坟茔");
			
			break;


case 15:
			command("say 江湖里打狗降龙。似他般义士，人间有几？");
me->set_temp("answer","沙场上驱夷破虏，如此样英雄，世上存乎");
			
			break;
case 16:
			command("say 一念之差，东躲西藏，追随贼汉子？");
me->set_temp("answer","二人唯别，红颜白骨，造就恶婆娘");
			
			break;
case 17:
			command("say 弹指无形,连就神功吞日月？");
me->set_temp("answer","举刀一快，断收凡欲奉葵花");
			
			break;



			}
me->set_temp("askduilian",1);
return 1;
}
int do_guess(string arg)
{
        int c;
        int i;

       object me = this_player();
       c = 1+random(2);
        if(!arg)
        return 0;
if(!me->query_temp("askduilian"))
{
command("say 你跟我要题目了么？");
return 1;
}

if (arg != me->query_temp("answer")) {
message_vision("$N傻乎乎上前对道："HIR""+arg+"！\n"NOR, me);
command("shake " + me->query("id")); 
 command("say 不对不对，这个下联对的太没文化");
//    me->delete_temp("answer");
return 1;
}

 else {

                me->add("SJ_Credit", c);
  message_vision("$N轻轻上前道：这有何难？且听我对："HIY""+me->query_temp("answer")+"！\n"NOR, me);
             
 command("say 嗯，很好很好，对的很工整嘛！");
                write(HIG "你获得了"HIR""+CHINESE_D->chinese_number(c)+""NOR""HIG"个书剑通宝。\n" NOR, me);
            
me->delete_temp("answer");
me->delete_temp("askduilian");
             return 1;

        }



}
