// 统一控制所有任务奖励。by lsxk  2008/1/7
// By Spiderii@ty 加个东东。洗手的JOB奖励比不洗手的降低一些
// By Spiderii@ty 转生玩家pot上限的限制。。刺激玩家转生
// update by lsxk@hsbbs 2008/06/27 添加转生玩家潜能上限限定
// Update by Jpei@feixue 放宽hardquo，修改描述。增加三种vip的识别


/* 参数说明：
    obj:    玩家自身
    job:    任务名称
    shenflag:    正负神标志,正神为1，负神为-1，不奖励神为0.
    potflag:    潜能标志，传递1，潜能超上限给，否则不超上限。
    credit:    通宝标志，0为无通宝奖励，-1为让系统根据经验值奖励计算通宝奖励，其他数值为指定通宝奖励数值.
    hardquo:    难度系数，数值从-10到20，数值越高，说明难度高，所以奖励多。负数的时候，奖励将会小于基础奖励。-10,经验奖励为0，奖励maxexp数量的潜能。
    PVPquo:    是否是玩家VS玩家类型的任务，即互动任务，如是，则请传递该PVP任务奖励加成系数(1-10)，否则为0.
    PVPlvl:    PVP类型任务奖励等级。例如襄阳任务：成功杀了3个对方的人，这个数值就是3。看任务标记。
    maxexp:    最大EXP数值，如果计算出来的EXP奖励大于这个，则取这个值。在计算加成奖励之前有效。为0则不限制。
    giver:    谁给的奖励，方便调用GIFT_D进行随机奖励。
*/

//全局定义基础经验值奖励
#define BASEEXP 100
//全局定义PVP类型任务基础经验奖励.
#define PVPEXP 180

//全局定义限定玩家增长的EXP上限为75M
#define LIMITEXP 100000000

//全局定义转生玩家潜能奖励基础上限为50000点
#define LIMITPOT 50000

//定义VIP Player的奖励加成系数，注意计算方式为：exp + exp * VIP奖励加成系数 / 100
#define VIPQUO 1

//定义节日奖励加成参数，注意计算方式为：exp + exp * 节日加成系数 / 10 
#define FESTIVAL 1

//定义试剑山庄进入奖励的最低EXP限制。
#define ENTER_MIN_EXP 2000000

#include <ansi.h>;

int get_reward(object obj, string job, int shenflag, int potflag, int credit, int hardquo, int PVPquo, int PVPlvl, int maxexp, mixed giver)
{
    int exp, expquo, pot, shen,exprelife;
    object ebook,kongxin,miweng,tianqi;
    string msg;

    msg = HIR"恭喜你！你成功的完成了" + HIG + job + HIR + "任务！你被奖励了：\n" + NOR;

//如果不是PVP类型，则基础经验奖励取全局定义，否则取PVP数值。
    if(!PVPquo){

//经验值部分

if (obj->query("combat_exp")<15000000) exp = BASEEXP * 1.1;
if (obj->query("combat_exp")>=15000000 && obj->query("combat_exp")<=25000000) exp = BASEEXP * 1.05 ;
if (obj->query("combat_exp")>=25000000 && obj->query("combat_exp")<=50000000) exp = BASEEXP;
if (obj->query("combat_exp")>50000000 && obj->query("combat_exp")<=75000000) exp = BASEEXP * 0.95;
if (obj->query("combat_exp")>75000000) exp = BASEEXP * 0.9;

//洗手惩罚20%
if(obj->query("no_pk") ) exp = exp * 0.95;



        if(hardquo > 20) hardquo = 20;
        if(hardquo < -10) hardquo = -10;

        if(hardquo >= 0)
            exp = exp + exp * hardquo /10 + random(exp * hardquo /10);
        else
            exp = exp + exp * hardquo /10 - random( -1 * exp * hardquo /10);

        if(hardquo == -10)
            exp = 0;
       if(hardquo == 20)   
           exp = exp * 6 ;
 }
    else{

//经验部分
        exp = PVPEXP;
        if(PVPquo > 10) PVPquo = 10;
        if(PVPquo < 0) PVPquo = 0;
        exp = exp + exp * PVPquo / 10 + random(50);  //计算最基础部分经验，即，不论输赢，参加的人都有。
        exp = exp + (exp - PVPEXP) * PVPquo * PVPlvl;  //计算额外奖励部分，也就是获得PVPlvl越多，奖励越多。
    }


//查看EXP是否超标
        if(maxexp != 0 && exp > maxexp)
            exp = maxexp + random(maxexp/10);

//普通月卡VIPplayer加成

        if(obj->query("registered") == 3)
            exp = exp + exp * VIPQUO * 5 / 100;
//年卡VIPplayer加成,标记为y-card-vip
        if(obj->query("y-card-vip"))
            exp = exp + exp * VIPQUO * 5 / 100;
//终身vip奖励 标记为buyvip
        if(obj->query("buyvip") )
            exp = exp + exp * VIPQUO * 10/ 100;


// 节日加成部分。
            exp = exp + exp * FESTIVAL / 10;

//参悟武学的经验获取部分，上限点数20点。
        
        if(obj->query("relife/exp_ext")){
        exprelife=exp*(int)obj->query("relife/exp_ext",1) / 20;
        }

// 限定玩家EXP到达上限后，极大程度地降低经验奖励。
        if(obj->query("combat_exp") > LIMITEXP){
            exp =  exp * 5 /100;
            tell_object(obj,"你觉得自己最近心神不宁，对武学的研究已经进入了举步惟艰的程度，似乎就是江湖传说的『"+HIG+"武学障"+NOR+"』。\n");
        }

        msg += HIW + chinese_number(exp) + HIC + "点" + HIM + "经验!\n"NOR;

//潜能部分
        pot = exp / 3;

        if(hardquo == -10)
            pot = maxexp;

        msg += HIW + chinese_number(pot) + HIC + "点" + HIY + "潜能!\n"NOR;



//shen部分
        if(shenflag==1){
            shen = exp / 2 + random(exp / 6);
            msg += HIW + chinese_number(shen) + HIC + "点正神！\n"NOR;
        }
        else if(shenflag == -1){
            shen = - exp / 2 - random(exp / 6);
            msg += HIW + chinese_number(-shen) + HIC + "点" + HIR + "负神！\n"NOR;
        }
        else shen = 0;



//通宝部分
        if(credit > 0) credit = random(exp / 100);
        if(credit != 0) msg += HIW + chinese_number(credit) + HIC + "个" + HIW + "通宝！\n"NOR;




//特殊部分，双倍经验
        expquo = 0;
        if(obj->query_condition("db_exp")){  // 双倍经验
            expquo = random(exp/2) + exp/3;
            msg += HIY + "精英状态期间，你额外地得到了" + HIW + chinese_number(expquo) + HIC + "点" + HIM + "经验！\n"NOR;
        }

//参悟武学EXP加成的描述
       if(obj->query("relife/exp_ext")) 
        msg += HBYEL + "你静下心来，反复回想刚才的任务过程，不禁豁然开朗。。你额外地得到了" + HIW + chinese_number(exprelife) + HIC + "点" + HIM + "经验！\n\n"NOR;
   
      
       obj->add("combat_exp",exp+exprelife+expquo);
       obj->add("potential",pot);

    if(potflag != 1 && obj->query("potential") > obj->query("max_pot") && !obj->query("relife/times"))
       obj->set("potential",obj->query("max_pot"));

    if(obj->query("relife/times") && obj->query("potential") > LIMITPOT * (int)obj->query("relife/times"))
       obj->set("potential",LIMITPOT * (int)obj->query("relife/times"));
       obj->add("shen",shen);
       obj->add("SJ_Credit",credit);
       obj->add("job_time/"+job, 1);
    tell_object(obj,msg);

//180:     log_file( "jobreward/"+job,sprintf("%s(%s)成功完成第%d次%s任务,获得 EXP:%d, EXPQUO:%d, POT:%d, SHEN:%d, CREDIT:%d"NOR,obj->name(),obj->query("id"),obj->query("job_time/"+job),job,exp,expquo,pot,shen,credit));
    
    
       if( random(500) == 100
        && random(500) < ( obj->query("int") + obj->query("str") + obj->query("dex") + obj->query("con") )

        && obj->query("combat_exp",1) >= 1000000 && (obj->query("y-card-vip") || obj->query("buyvip") ))
   	{
    
  tell_object(obj, HIW"你行走江湖，快意恩仇，对各地的风土人情偶有所得，不由得有了一丝感悟的见解。你获得了一本"HIY"精英之书"HIW"！\n"NOR);
       ebook=new("/u/jpei/ebook");
       ebook ->move(obj);
    log_file("jobreward/ebook",sprintf("%s(%s)成功完成第%d次%s任务时获得一本精英之书！\n"NOR,obj->name(),obj->query("id"),obj->query("job_time/"+job),job));
    }


       if( random(1000) == 100
        && random(500) < ( obj->query("int") + obj->query("str") + obj->query("dex") + obj->query("con") )
        && obj->query("combat_exp",1) >= 1000000 && (obj->query("y-card-vip") || obj->query("buyvip") ))
   	{
    
  tell_object(obj, HIW"胜败乃兵家常事，即使任务失败也可以重头再来！"HIY"空心散"HIW"乃是忘忧解烦的良药，赶紧收下吧！\n"NOR);
       kongxin=new("/u/jpei/kongxin");
       kongxin->move(obj);
    log_file("jobreward/kongxin",sprintf("%s(%s)成功完成第%d次%s任务时获得一包空心散！\n"NOR,obj->name(),obj->query("id"),obj->query("job_time/"+job),job));
    }


       if( random(400) == 100
        && random(400) < ( obj->query("int") + obj->query("str") + obj->query("dex") + obj->query("con") )
        && obj->query("combat_exp",1) >= 1000000 && (obj->query("y-card-vip") || obj->query("buyvip") ))
   	{
    
  tell_object(obj, HIW"行走江湖，一包田七鲨胆散怎么能不常备应急呢？你被赠送了一包"HIY"田七鲨胆散"HIW"！\n"NOR);
       tianqi=new("/u/jpei/tianqi");
       tianqi->move(obj);
    log_file("jobreward/tianqi",sprintf("%s(%s)成功完成第%d次%s任务时获得一包田七鲨胆散！\n"NOR,obj->name(),obj->query("id"),obj->query("job_time/"+job),job));
    }


       if( random(1200) == 100
        && random(600) < ( obj->query("int") + obj->query("str") + obj->query("dex") + obj->query("con") )
        && obj->query("combat_exp",1) >= 1000000 && (obj->query("y-card-vip") || obj->query("buyvip") ))
   	{
    
  tell_object(obj, HIR"人靠衣装马靠鞍，"HIY"珠宝商秘闻"HIR"可以免费获得一份珠宝首饰，不无小补哦！\n"NOR);
       miweng=new("/u/jpei/miweng");
       miweng->move(obj);
    log_file("jobreward/miweng",sprintf("%s(%s)成功完成第%d次%s任务时获得一份珠宝商秘闻！\n"NOR,obj->name(),obj->query("id"),obj->query("job_time/"+job),job));
    }





    if(giver)
        GIFT_D->check_count(obj,giver,job,0);
    return 1;
}
