#include <ansi.h>
#include <command.h>
inherit F_DBASE;
#include <command.h>
#define QINGLONG "/d/hudong/xiangyang/qinglongmen"
#define BAIHU "/d/hudong/xiangyang/baihumen"
#define ZHUQUE "/d/hudong/xiangyang/zhuquemen"
#define XUANWU "/d/hudong/xiangyang/baihumen"
void create()
{
        seteuid(ROOT_UID);
     set("channel_id", "襄阳大战精灵");
        
        set("name","");
	remove_call_out("xyjob_1");
call_out("xyjob_1", 5); 
}
string* xyjob_room = ({
        "d/hudong/xiangyang/baihumen",
        "d/hudong/xiangyang/bank",
        "d/hudong/xiangyang/baozipu",
        "d/hudong/xiangyang/bcx1",
        "d/hudong/xiangyang/bcx2",
        "d/hudong/xiangyang/bcx3",
        "d/hudong/xiangyang/bcx4",
        "d/hudong/xiangyang/bhmnj",
        "d/hudong/xiangyang/bingying",
        "d/hudong/xiangyang/bjie1",
        "d/hudong/xiangyang/bjie2",
        "d/hudong/xiangyang/bjie3",
        "d/hudong/xiangyang/chalou",
        "d/hudong/xiangyang/chalou2",
        "d/hudong/xiangyang/chayedian",
        "d/hudong/xiangyang/chemahang",
        "d/hudong/xiangyang/eroad1",
        "d/hudong/xiangyang/chengyipu",
        "d/hudong/xiangyang/chucshi",
        "d/hudong/xiangyang/cross1",
        "d/hudong/xiangyang/cross2",
        "d/hudong/xiangyang/chengyipu",
        "d/hudong/xiangyang/damen",
        "d/hudong/xiangyang/datiepu",
        "d/hudong/xiangyang/dcx1",
        "d/hudong/xiangyang/dcx2",
        "d/hudong/xiangyang/dcx3",
        "d/hudong/xiangyang/dcx4",
        "d/hudong/xiangyang/dcx5",
        "d/hudong/xiangyang/djie1",
        "d/hudong/xiangyang/djie2",
        "d/hudong/xiangyang/doufufang",


        "d/hudong/xiangyang/dpailou",
        "d/hudong/xiangyang/eroad1",
        "d/hudong/xiangyang/feizhai",
        "d/hudong/xiangyang/guangc",
        "d/hudong/xiangyang/junying",
        "d/hudong/xiangyang/mujiangpu",
        "d/hudong/xiangyang/ncx1",
        "d/hudong/xiangyang/ncx2",
        "d/hudong/xiangyang/ncx4",
        "d/hudong/xiangyang/ncx3",
        "d/hudong/xiangyang/ncx5",
        "d/hudong/xiangyang/njie1",
        "d/hudong/xiangyang/njie2",
        "d/hudong/xiangyang/njie3",
        "d/hudong/xiangyang/nroad1",
        "d/hudong/xiangyang/outeroad1",
        "d/hudong/xiangyang/outnroad1",
        "d/hudong/xiangyang/outsroad1",
        "d/hudong/xiangyang/outwroad1",
        "d/hudong/xiangyang/qinglongmen",
        "d/hudong/xiangyang/shaobingpu",
        "d/hudong/xiangyang/shuoshug",
        "d/hudong/xiangyang/sishu",
        "d/hudong/xiangyang/xcx1",
        "d/hudong/xiangyang/xiaocd",
        "d/hudong/xiangyang/xcx2",
        "d/hudong/xiangyang/xcx3",
        "d/hudong/xiangyang/xcx4",
        "d/hudong/xiangyang/xcx5",
        "d/hudong/xiangyang/xiyuan",
        "d/hudong/xiangyang/xjie",
        "d/hudong/xiangyang/xpailou",



        "d/hudong/xiangyang/xuanwumen",
        "d/hudong/xiangyang/xyudian",
        "d/hudong/xiangyang/yamen",
        "d/hudong/xiangyang/yaopu",
        "d/hudong/xiangyang/yingzhang",
        "d/hudong/xiangyang/ymzhengting",
        "d/hudong/xiangyang/zahuopu",
        "d/hudong/xiangyang/zhuquemen",
        "d/hudong/xiangyang/zqmnj",
        "d/hudong/xiangyang/zrdian",
});

void xyjob_1() //任务准备
{
       object obj,obj1,obj2, obj3, env;


message("channel:chat", HIY"【"HIW"江湖传闻"HIY"】"HIC"吕文德(Lv wende)：郭大侠，蒙古大军已逼近襄阳，朝廷还未派来援兵，这可如何是好？\n"NOR,users());
    message("channel:chat", HIY"【"HIW"江湖传闻"HIY"】"HIC"郭靖(Guo jing)：我欲广发英雄帖募集天下英雄誓死坚守襄阳城！\n"NOR,users());
    message("channel:chat", HIY"【"HIW"江湖传闻"HIY"】"HIC"蒙哥(Meng ge)：大宋官兵个个酒囊饭袋，看我蒙古勇士个个神勇无比，何况襄阳城内又有内应，大事定成！\n"NOR,users());
    message("channel:chat", HIY"【"HIW"江湖传闻"HIY"】"HIC"金轮法王(Jinlun fawang)：哈哈哈！郭靖阿郭靖，你命不久矣！！\n"NOR,users());
message("channel:chat", HIY"【"HIW"江湖传闻"HIY"】"HIC"郭靖(Guo jing)：哼，异族番邦休得猖狂，须教尔等见识中原武林豪杰的手段！\n"NOR,users());
CHANNEL_D->do_channel( this_object(), "sys", "襄阳大战系统已经启动。\n"); 
if(!objectp(find_object("/d/xiangyang/damen")))
    load_object("/d/xiangyang/damen");
    obj = find_living("shuoshu laozhe");
    if(!obj || !objectp(obj)) obj= new("/d/xiangyang/npc/oldman");
    env = environment(obj);
    if(!env || file_name(env)!="/d/xiangyang/damen")
    obj->move("/d/xiangyang/damen");
    obj->set("hd_start",1); //   襄阳报名    
CHANNEL_D->do_channel( obj, "chat", "襄阳大战系统已经启动，各位玩家可到武馆大门处报名参加(ask laozhe about 报名)。\n");    



if(!objectp(find_object("/d/hudong/xiangyang/defend")))
    load_object("/d/hudong/xiangyang/defend");
    obj1 = find_living("lv wende");
    if(!obj1 || !objectp(obj1)) obj1= new("/d/hudong/xiangyang/npc/lvwende");
    env = environment(obj1);
    if(!env || file_name(env)!="/d/hudong/xiangyang/defend")
    obj1->move("/d/hudong/xiangyang/defend");
    obj1->set("hd_start",1);                 //开始报名

    if(!objectp(find_object("/d/hudong/xiangyang/attack")))
    load_object("/d/hudong/xiangyang/attack");
    obj2 = find_living("meng ge");
    if(!obj2 || !objectp(obj2)) obj2= new("/d/hudong/xiangyang/npc/mengge");

    env = environment(obj2);
    if(!env || file_name(env)!="/d/hudong/xiangyang/attack")
    obj2->move("/d/hudong/xiangyang/attack");
    obj2->set("hd_start",1);



 remove_call_out("xyjob_1");
call_out("xyjob_2", 60,obj,obj1,obj2);  // 时间长一点
}
void xyjob_2(object obj,object obj1,object obj2)
{
  if(obj) obj ->delete("hd_start");       //停止报名
if(obj1) obj1 ->delete("hd_start");       //停止报名
if(obj2) obj2 ->delete("hd_start");       //停止报名
 message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"襄阳大战将在六十秒后开始！\n"NOR,users());
call_out("xyjob_3", 60);   // 时间长一点
}

void xyjob_3()
{
string room;
int i;
int at,df;
object *ob;
object *attacker = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);

if (df < 1)
        {
               message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"襄阳守军高挂免战牌坚守不出，蒙古大军只能望城兴叹！\n"NOR,users());
                remove_call_out("xyjob_3");
                call_out("xyjob_1", 3600);
        }
        else if (at < 1)
        {
                message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"蒙古先锋苦等后援未到，只能暂缓攻城！\n"NOR,users());
                remove_call_out("xyjob_3");
                call_out("xyjob_1", 3600);
        }
        else
        {       


                message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"襄阳大战开始，双方生死各安天命！\n"NOR,users());
message("channel:chat", HIY"【"HIW"江湖传闻"HIY"】"HIC"吕文德(Lv wende)：俺的娘啊！蒙古军队来了，快关城门！\n"NOR,users());

 // reset_eval_cost();

for(i=0;i<df;i++){
room = xyjob_room[random(sizeof(xyjob_room))];

    	if(!defender[i]->is_character() || defender[i]->is_corpse() || defender[i]->is_ghost()|| defender[i]->apply_condition("killer")){
    		defender[i]->delete_temp("互动任务");  //不是活人,杀人犯不传送
    		continue;      	
 }

               	defender[i]->set_temp("互动任务/襄阳大战/阵营",1);
defender[i]->move(room);
    }
   for(i=0;i<at;i++){
    	if(!attacker[i]->is_character() || attacker[i]->is_corpse() || attacker[i]->is_ghost()|| attacker[i]->apply_condition("killer")){
    		attacker[i]->delete_temp("互动任务");  //不是活人,杀人犯不传送
    		continue;      	
 }

               	attacker[i]->set_temp("互动任务/襄阳大战/阵营",2);
attacker[i]->move("d/hudong/xiangyang/zhangwai");
    

              
}
call_out("xyjob_4",900);

}
}

void xyjob_4()
{
string room;
int i;
int at,df;
object *ob;
object *attacker = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
if (sizeof(attacker) > sizeof(defender))
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"听说蒙古兵攻下了襄阳城！");
                for(i = 0; i < at; i++)
                        attacker[i]->add_temp("xyjob/attack", 1);
        }
        else
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"听说襄阳守军杀退了蒙古军！");
                for(i = 0; i < df; i++)
                        defender[i]->add_temp("xyjob/defend", 1);
        }

remove_call_out("xyjob_4");
	call_out("xyjob_5", 5);

}


void xyjob_5() // 发放奖励
{

int i;
int at,df;
int exp, nexp, pot, SJ_Credit;

object *ob;
object *attacker = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
        
        for(i = 0; i < at; i++)
        {
                exp = attacker[i]->query_temp("xyjob/attack")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*df)
                        exp = 1000 + 200*df -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
                pot = exp/6 +random(exp/10);
                SJ_Credit = exp*2/400;
                attacker[i]->add("SJ_Credit",SJ_Credit);
                attacker[i]->add("combat_exp",exp);
                if(attacker[i]->query("potential") + pot > attacker[i]->query("max_pot"))
                        attacker[i]->set("potential", attacker[i]->query("max_pot"));
                else
                        attacker[i]->add("potential", pot);
                message_vision(HIW"\n$N获得了"+CHINESE_D->chinese_number(exp)+
                "点经验，"+ CHINESE_D->chinese_number(pot)+
                "点潜能的奖励。\n"+HIR+"\n$N额外还获得了"+ CHINESE_D->chinese_number(SJ_Credit)+"个天涯通宝\n"NOR, attacker[i]);
                attacker[i]->add("shen",-nexp);
                message_vision(HIW"\n$N觉得一股邪念自心中生起。\n"NOR,attacker[i]);
                attacker[i]->add("job_time/襄阳攻防",1);
                attacker[i]->clear_conditions_by_type("poison");
                attacker[i]->clear_conditions_by_type("hurt");
                attacker[i]->clear_conditions_by_type("busy");
                attacker[i]->clear_conditions_by_type("zhenqi");
                attacker[i]->remove_all_killer();
                attacker[i]->dismiss_team();
                attacker[i]->clear_condition("job_busy");
                log_file("job/xyjob", sprintf("%s %s(%s)%d次攻城得到经验%d，潜能%d，通宝%d。\n",
                ctime(time())[4..19],attacker[i]->name(1),attacker[i]->query("id"),(int)attacker[i]->query("job_time/襄阳攻防"),exp,pot,SJ_Credit));
        }
        for(i = 0; i < df; i++)
        {
                exp = defender[i]->query_temp("xyjob/defend")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*at)
                        exp = 1000 + 200*at -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
                SJ_Credit = exp*2/400;
                pot = exp/6 +random(exp/10);
                defender[i]->add("SJ_Credit",SJ_Credit);
                defender[i]->add("combat_exp",exp);
                if (defender[i]->query("potential") + pot > defender[i]->query("max_pot"))
                        defender[i]->set("potential", defender[i]->query("max_pot"));
                else
                        defender[i]->add("potential", pot);
                message_vision(HIW"\n$N获得了"+CHINESE_D->chinese_number(exp)+
                "点经验，"+ CHINESE_D->chinese_number(pot)+
                "点潜能的奖励。\n"+HIR+"\n$N额外还获得了"+ CHINESE_D->chinese_number(SJ_Credit)+"个天涯通宝\n"NOR, defender[i]);
                defender[i]->add("shen",nexp);
                message_vision(HIW"\n$N的侠义正气上升了！\n"NOR,defender[i]);
                defender[i]->add("job_time/襄阳攻防",1);
                defender[i]->clear_conditions_by_type("poison");
                defender[i]->clear_conditions_by_type("hurt");
                defender[i]->clear_conditions_by_type("busy");
                defender[i]->clear_conditions_by_type("zhenqi");
                defender[i]->remove_all_killer();
                defender[i]->dismiss_team();
                defender[i]->clear_condition("job_busy");
                log_file("job/xyjob", sprintf("%s %s(%s)%d次守城得到经验%d，潜能%d，天涯通宝%d。\n",
                ctime(time())[4..19],defender[i]->name(1),defender[i]->query("id"),(int)defender[i]->query("job_time/襄阳攻防"),exp,pot,SJ_Credit));
        }
        remove_call_out("xyjob_5");
remove_call_out("xyjob_1");
        call_out("xyjob_1", 1800);
        }









void xy_attackbh()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"白虎门已被蒙古大军攻破，蒙古先锋从白虎门进入襄阳！\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"你被奖励了：" +
		chinese_number(exp) + "点实战经验，" +
		chinese_number(pot) + "点潜能。"+
		"加油啊，已经胜利了一步了。\n"NOR);


}
call_out("boss_guo",3);
}

void xy_attackql()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"青龙门已被蒙古大军攻破，蒙古先锋从青龙门进入襄阳！\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"你被奖励了：" +
		chinese_number(exp) + "点实战经验，" +
		chinese_number(pot) + "点潜能。"+
		"加油啊，已经胜利了一步了。\n"NOR);


}
call_out("boss_yang",3);
}
void xy_attackzq()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"朱雀门已被蒙古大军攻破，蒙古先锋从朱雀门进入襄阳！\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"你被奖励了：" +
		chinese_number(exp) + "点实战经验，" +
		chinese_number(pot) + "点潜能。"+
		"加油啊，已经胜利了一步了。\n"NOR);


}
call_out("boss_huangrong",3);

}

void xy_attackxw()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("互动任务/襄阳大战/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"【"HIR"系统提示"HIY"】"HIC"玄武门已被蒙古大军攻破，蒙古先锋从玄武门进入襄阳！\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"你被奖励了：" +
		chinese_number(exp) + "点实战经验，" +
		chinese_number(pot) + "点潜能。"+
		"加油啊，已经胜利了一步了。\n"NOR);


}
call_out("boss_huang",3);
}

void boss_guo()
{
// object boss = new("d/hudong/xiangyang/npc/guo");
object obj;
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"便在此时，从白虎门城楼上跃下一中年男子，如矫龙惊蛇般飘落当下。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"众人抬眼观看，正是守卫襄阳的郭靖大侠，一时间蒙古大军人人胆寒。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"郭靖(Guo jing)：蒙古鞑子休要猖狂，待郭某人与尔等见个高低！\n"NOR,users());
 obj = find_living("guo jing");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/guo");
obj ->move("d/hudong/xiangyang/baihumen");
}

void boss_yang()
{

object obj;
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"便在此时，从青龙门城楼上跃下一青年男子，大袖飘飘轻轻落在当下。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"众人定睛观瞧，此人一只袖管空空荡荡，脸上英武气概却丝毫不差。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"杨过(Yang guo)：郭伯伯，小侄杨过来迟，就让我领教一下蒙古高手的绝技！\n"NOR,users());
 obj = find_living("yang guo");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/yang");
obj ->move("d/hudong/xiangyang/qinglongmen");
}

void boss_huang()
{

object obj;
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"城门破时，从玄武门城楼上方跃下一青袍老人，一脸冷峻飘落落在当下。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"众人仔细一看，此人一头白发随风飘荡，更突显出老而弥坚的矍铄之意。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"黄药师(Huang Yaoshi)：哈哈哈，素闻蒙古乃是蛮夷粗鄙之人，看来言不我欺！\n"NOR,users());
 obj = find_living("yang guo");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/huang");
obj ->move("d/hudong/xiangyang/xuanwumen");
}

void boss_huangrong()
{

object obj;
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"城门将破，从朱雀门城楼上方跃下一青年女子，一身白衣，手持竹棒飘落在当下。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"众人仔细一看，正是丐帮前任帮主襄阳大侠郭靖之妻，黄蓉黄女侠，巾帼不让须眉。\n"NOR,users());
message("channel:chat", HIY"【"HIR"襄阳战事"HIY"】"HIC"黄蓉(Huang Rong)：鞑子敢尔！今天就让尔等见识中原武林豪杰的英雄手段！\n"NOR,users());
 obj = find_living("yang guo");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/huangrong");
obj ->move("d/hudong/xiangyang/zhuquemen");
}
