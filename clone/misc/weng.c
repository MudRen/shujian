#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(CYN"瓦瓮"NOR, ({ "wa weng", "wa" ,"weng"}) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个用瓦做成的瓮，里面黑洞洞的，腥气扑鼻似乎装有什么毒物。\n"
);
                set("unit", "个");
                set("value", 80);
set("no_get",1);
set("no_give",1);
set("no_cun",1);
               
}
}
void init()
{
        add_action("do_shenshou", "shenshou");
}

int do_shenshou(string arg)
{
object me,ob;
me = this_player();
ob = this_object();

if(ob->query("owner")!=me->query("id"))
return notify_fail("你从哪弄来的东东？\n");

if (!arg)
 return notify_fail("你要干什么?\n");

if (arg!="wa weng" && arg!="wa" && arg!="weng")
return notify_fail("你要往哪里伸手？\n");
if ( !present("fanwen book", me)) return 0;
message_vision(HIR"$N咬紧牙齿，闭上眼睛，右手慢慢伸入瓦瓮。\n"NOR,me);
message_vision(HIR"$N手指一伸入瓮中，中指指尖上便如针刺般\n"
                    "忽然剧痛，忍不住将手一缩，只见一条冰蚕\n"
                    "正咬住了自己中指，原来是在吸血...\n"NOR,me);
me->start_busy(999);
 remove_call_out("thinking");
           call_out("thinking",3, me );

return 1;
}

int thinking(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n你全身发毛,心中大骇。好在冰蚕吸血，并不甚痛，但见那冰蚕\n"
                    "渐渐肿大起来，自己的中指上却也隐隐罩上了一层深紫之色。\n"
                    "紫色由浅而深，慢慢转成深黑，再过一会，黑色自指而掌，更\n"
                    "自掌沿手臂上升。你这时已将性命甩了出去，反而处之坦然，嘴\n"
                    "角边也微微露出笑容...\n"NOR);


remove_call_out("thinking1");
call_out("thinking1",4, me );
}

int thinking1(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n不多时，只见一道黑气已蔓延至腋窝，同时一条手臂也麻痒起来，\n"
                    "霎时之间，便如千万只跳蚤在同时咬啮一般。\n"NOR);

tell_object(me,HIB"\n你纵声大叫，跳起身来，伸手去搔，一搔之下，更加痒得厉害，\n"
                    "好似骨髓中、心肺中都有虫子爬了进去，蠕蠕而动。痛可忍而\n"
                    "痒不可耐，你跳上跳下，高声大叫，将头用力碰撞墙壁，当当\n"
                    "声响，只盼自己即时晕了过去，失却知觉，免受这般难熬的奇痒。\n"NOR);

remove_call_out("thinking2");
call_out("thinking2",5, me );
}

int thinking2(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n又撞得几下，啪的一声，怀中掉出一件物事，正是拾到的那本\n"
                    "梵文经书。这时剧痒之下，也顾不得去拾，但见那书从中翻开。\n"
                    "你全身说不出的难熬，滚倒在地，乱擦乱撞。过得一会，俯伏\n"
                    "着只是喘息，泪水、鼻涕、口涎都从嘴缝中流出来，滴在经书上。\n"
                    "昏昏沉沉中也不知过了多少时候，书页上已浸满了涕泪唾液，\n"
                    "无意中一瞥，忽见书页上的弯弯曲曲的文字之间，竟现出一行\n"
                    "汉字：“摩伽陀国欲三摩地断行成就神足经。”这些字你也识\n"
                    "不周全，又见汉字旁有个外国僧人图形。这僧人姿式奇特，脑\n"
                    "袋从胯下穿过，伸了出来，双手抓着两只脚。\n"NOR);

remove_call_out("thinking3");
call_out("thinking3",5, me );
}

int thinking3(object me)
{
object ob,ob1;
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIB"\n你也没心绪去留神书上的古怪姿势，只觉痒得几乎气也透不过来\n"
                    "了，扑在地下，乱撕身上衣衫，将上衣和裤子撕得片片粉碎，将\n"
                    "肌肤往地面上猛力摩擦，擦得片刻，皮肤中便渗出血来。你乱滚\n"
                    "乱擦，突然一不小心，脑袋竟从双腿间穿过。右手自然而然地抓\n"
                    "住了右脚。\n"NOR);

tell_object(me,HIB"\n做了这个姿势后，身上麻痒之感虽一般无二，透气却顺畅得多了。\n"
                    "当下也不急于要将脑袋从胯下缩回来，便这么伏在地下，索性依\n"
                    "照图中僧人姿势，连左手也去握住了左脚，下颚抵地。这么一来，\n"
                    "姿势已与图中的僧人无异，透气更加舒服了。\n"NOR);

tell_object(me,HIB"\n你惊奇之下，也不暇去想其中原因，只这般照做，做到三十余\n"
                    "次时，臂上已仅余微痒，再做十余次，手指、手掌、手臂各处已\n"
                    "全无异感。\n"NOR);
if( random(me->query("kar"))> 28  && random(15)==1 && me->query("buyvip"))
{
remove_call_out("thinking4");
call_out("thinking4",5, me );
}
else 
tell_object(me,HIG"\n你坐起身来，沉思良久，不知如何是好....\n"NOR);
message_vision(HIC"\n$N摇了摇头，深深地叹了口气。\n"NOR,me); 
tell_object(me,HBBLU"\n很可惜，你本次尝试冰蚕毒掌解谜失败！\n"NOR);
tell_object(me,HBBLU"请继续努力！\n\n"NOR);
log_file("quest/bingcan",sprintf("%8s%-10s尝试解开冰蚕毒掌秘密失败，经验：%d，福：%d，次数：%d。\n",
me->name(),"("+me->query("id")+")", me->query("combat_exp"),
me->query("kar"), me->query("quest/bingcan/fail")), me);


me->add("quest/bingcan/fail",1);
me->delete_temp("waweng");
me->start_busy(3);
me->add("qi",-me->query("max_qi")*2/5);
me->add("eff_qi",-me->query("max_qi")*2/5); 
destruct(present("fanwen book", me));
destruct(present("wa weng", me));
return 0;
}

int thinking4(object me)
{
if(!me) return 0;
if ( !present("wa weng", me)) return 0;
if ( !present("fanwen book", me)) return 0;
tell_object(me,HIW"\n突然食指尖上微微一痒，一股寒气犹似冰箭，循着手臂，迅速\n"
                    "无伦地射入胸膛，当即以《欲三摩地断行成就神足经》中运功\n"
                    "之法，化解毒气，血液为冰蚕吸入体内后，又回入他手指血管，\n"
                    "将这剧毒无比的冰蚕寒毒吸进了体内。\n"NOR);
  
tell_object(me,HIY"\n你坐起身来，沉思良久，恍然大悟....\n"NOR);
message_vision(HIC"\n$N坐起身来，脑子恢复了清醒。\n"NOR,me); 
tell_object(me,HBBLU"\n恭喜你，你练成了「冰蚕毒掌」！\n"NOR);
me->set("quest/bingcan/pass", 1);
                me->set_skill("bingcan-duzhang",10+random(5));
                
                tell_object(me,HIC"你的冰蚕毒掌进步了。\n", me);
log_file("quest/bingcan",sprintf("%8s%-10s成功解开冰蚕毒掌秘密，经验：%d，福：%d，次数：%d。\n",
                        me->name(),"("+me->query("id")+")", me->query("combat_exp"),
                        me->query("kar"), me->query("quest/bingcan/fail")), me);                 
destruct(present("fanwen book", me));
destruct(present("wa weng", me));
return 1;
}
