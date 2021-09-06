// card.c 绿卡
// Created by Numa 19990828 & Will Modify then and then...
// Bcz my alias too long can't .......
// add by tangfeng

#define S_VISION "Version 2.0版"
#define COPY_NPC "/tmp/tangfeng/shield_npc"
#include <ansi.h>
#include <command.h>
#include <login.h>
#include <armor.h>  
//#include <combat.h>

inherit SHIELD;
#include <combat_msg.h>
string setcolor();
int copy_skill(object me, object ob);
int update_player(object me);
//void mofa_start(object me,string color);
void mofa_damage(string type,object me,object ob,int i);
//void zhaohuan_fight(object obj,object me);
void create()
{
        set_name(HIY"炎之纹章"NOR,({"fire emblem","emblem","fire"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  
        set("long",HIR"巫师专用饰品\n"NOR);
        set("unit","枚");
        set("value",100000);
        seteuid(getuid());
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
	set("material", "steel");                 
        set("armor_prop/armor", 200);
        }
       
        setup();
}

void init()
{
        object me = this_player();
        
        if (me && present(this_object(), me))
        {
                add_action("help","help");//帮助
		add_action("do_qidong","qidong");//启动超强防御
		add_action("do_qu","qu");//去任何地方						
		add_action("do_kan","kan");//察看
		add_action("do_mingling","ml"); //命令   
		add_action("do_whohave","wh");//察看物品
		add_action("do_di","di");//察看玩家
		add_action("do_cip","cip");//察看ip
		add_action("do_call","hj");//call
		add_action("do_cplayer","cplayer");//copy玩家的一个npc
		add_action("do_cnpc","cnpc");//随意设定一个npc
		add_action("do_cparty","cparty");//随意设定自己一个门派武功
		add_action("do_cskill","cskill");//随意copy玩家skills					
		add_action("add_spel_skill","askill");//随意copy玩家skills
		wear();        
        }
        
}

int query_autoload()
{
        if (wizardp(environment())) return 1;
        return 0;
}

int help(string arg)
{
        if (arg == "emblem")
        {
                write("        
目前可用的命令有：        
命令                 参数                          用途            
————————————————————————————————————————
qidong  (qidong ok/qidong none)             [启动传说中的超能盾牌]
qu      (档案名、人名、已设定名[help qu])   [去任何想去的地方！]
kan     (人物的名称或简称)                  [可以直接查看人物档案]
ml      (Npc的Id)       (要执行的命令)      [可以直接让Npc执行指令]
wh      (物品的Id)                          [直接查找线上物品所属]
di      (内定值[help di])                   [可以对玩家资料进行对比]");
    	write("
cip     (Ip地址)                            [玩家地址反查看]
hj      (物件)->(函数)(参数)                [可以呼叫Npc啦，呵呵]
cplayer (玩家Id)                            [可以复制玩家进行测试]
cnpc    (门派、等级等[help cnpc])           [可以随意复制一个梦蝶楼Npc]
cparty  (id,门派、等级[help cparty)         [可以方便地设定自己或者他人武功]
cskill  (玩家)                              [可以随意copy玩家的武功]
————————————————————————————————————————        
                                     ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR
        );
        return 1;
        }
        
        if (arg == "qu")
        {
                write(@QU
        
        目前所设定的位置：
        
        th      桃花岛积翠亭                    /d/thd/jicui.c
        gy      归云庄前厅                      /d/thd/guiyun/qianting.c
        nj      牛家村小店                      /d/thd/niujia/xiaodian.c
        mj      明教光明顶                      /d/mingjiao/gmd.c
        tl      天龙寺白石路                    /d/tls/road.c
        gb      丐帮大信分舵                    /u/explorer/gb/fenduo1.c
        gm      古墓派入口                      /d/gumu/rukou.c
        mr      慕容燕子坞                      /d/mr/yanziwu.c
        xs      雪山殿前广场                    /d/xueshan/guangchang.c
        fm      少林寺伏魔圈                    /d/shaolin/fumoquan.c
        hs      华山前厅                        /d/huashan/qianting.c
        sl      少林寺平台                      /d/shaolin/pingtai.c
        xy      襄阳丁字路口                    /d/xiangyang/cross2.c
        wg      襄阳武馆大院                    /d/wuguan/dayuan.c
        wd      武当派三清殿                    /d/wudang/sanqing.c
        ss      嵩山封禅台                      /d/songshan/fengchantai.c
        yz      扬州客店                        /d/city/kedian.c
        gc      回疆高昌迷宫                    /d/hj/mg-room2.c
        ms      桃花岛墓道                      /d/thd/mudao2.c
        wi      巫师休息室                      /d/wizard/wizard_room.c
        dl      大理镇南王府大门                /d/dali/wangfu/damen.c
        em      峨嵋山华藏庵广场                /d/emei/huazangangc.c
        sd      古墓杨过处                      /d/gumu/jqg/xiaoshi.c
        ld      神龙岛林间空地                  /d/sld/kongdi.c
        xx      星宿海日月洞口                  /d/xingxiu/ryd1.c
QU
);
				write("
                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
                return 1;
        }
        
        if (arg == "di")
        {
                write(@DI
        
        目前内定有：
        
        exp                                     [显示每小时所得经验大于1000的玩家信息]
        expall                                  [显示所有在线玩家的每小时所得的经验值]
DI
);
				write("                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR   
);
                return 1;
        }
        if (arg == "cnpc")
        {
                write(@CNPC
        
命令格式		      cnpc |<门派编号>|<难度级数>|<空手是否>|
内定参数说明
门派编号：
1——武当           2——华山           3——嵩山           4——古墓
5——丐帮           6——铁掌           7——大轮寺         8——慕容     
9——神龙岛         10——星宿          11——峨嵋          12——明教
13——桃花岛        14——天龙          15——少林          16——昆仑 
17——九阴大全      18——蛤蟆功        19——辟邪剑        20——金蛇剑
难度级数： 
1——9
空手设定： 
1——空手           2——兵器           3——随机           4——空手+互搏       
        
CNPC
);
				write("
                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR


);
                return 1;
        }
       if (arg == "cparty")
        {
                write(@CPARTY
        
命令格式		      cparty <player id> <门派> <skills level>
内定参数说明
门派编号：
wd——武当          hs——华山          ss——嵩山          gm——古墓
gb——丐帮          tz——铁掌          dls——大轮寺       mr——慕容     
sld——神龙岛       xx——星宿          em——峨嵋          mj——明教
thd——桃花岛       tls——天龙         sl——少林          kl——昆仑 
wudu——五毒教      xiaoyao——逍遥派   tiandi——天地会    xuejian——雪山剑派
        
CPARTY
);
				write("
                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR


);
                return 1;
        }
        
        if (arg == "askill")
        {
                write(@ASKILL
        
命令格式	
			askill <player id> <quest编号> <skills level>
内定参数说明
武功编号：
			feihu   飞狐全套   qzwds    千蛛万毒手
			jsj     金蛇剑     hmg      蛤蟆功
			9yin1   九阴下     9yin2    九阴全
			lbwb    凌波微步   szj      连城诀全套     
        
ASKILL
);
				write("
                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR


);
        return 1;
		}
}


int do_cskill(string arg)
{
	object ob;
	object me=this_player();
    
	if (!arg)	
		return notify_fail("cskill <player id>\n");

    if (! objectp(ob = present(arg, environment(me))))//判断对象是否在身旁
		return notify_fail("你眼前没有这个人。\n");

	if (!wizardp(me))//判断是否是巫师
		return notify_fail("只有巫师才可以复制别人的武功。\n");
    
	copy_skill(me, ob);//开始调用函数COPY武功和状态
	message_vision(HIM "$N口中念念有词，只见一道红光笼罩了$N和$n。\n" NOR,me, ob);//显示出状态
	return 1;
}

int copy_skill(object me, object ob)
{
	mapping hp_status, skill_status, map_status, prepare_status;
	mapping my;
	string *sname, *mname, *pname;
	int i, temp;

	if (mapp(skill_status = me->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
	{
		skill_status = me->query_skills();
		sname = keys(skill_status);//传回所有自己的功夫阵列

		temp = sizeof(skill_status);
		for (i = 0; i < temp; i++)
			me->delete_skill(sname[i]);//删除自己所有功夫
	}

	if (mapp(skill_status = ob->query_skills()))//判断对象是否有功夫，如有将用这个函数复制全部功夫
	{
		skill_status = ob->query_skills();
		sname = keys(skill_status);//传回所有对象功夫阵列

		for (i = 0; i < sizeof(skill_status); i++)
			me->set_skill(sname[i], skill_status[sname[i]]);//为自己复制所有功夫
	}

	if (mapp(map_status = me->query_skill_map()))//判断自己是否有已装配的基本功夫
	{
		mname = keys(map_status);

		temp = sizeof(map_status);
		for (i = 0; i < temp; i++)
			me->map_skill(mname[i]);
	}

	if (mapp(map_status = ob->query_skill_map()))//判断对象所装配的基本功夫，如有将用这个函数复制
	{
		mname = keys(map_status);

		for(i = 0; i < sizeof(map_status); i++)
			me->map_skill(mname[i], map_status[mname[i]]);
	}

	if (mapp(prepare_status = me->query_skill_prepare()))//判断自己是否有已装配的特殊功夫
	{
		pname = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i = 0; i < temp; i++)
			me->prepare_skill(pname[i]);
	}

	if (mapp(prepare_status = ob->query_skill_prepare()))//判断对象所装配的特殊功夫，如有将用这个函数复制
	{
		pname = keys(prepare_status);

		for(i = 0; i < sizeof(prepare_status); i++)
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}

	hp_status = ob->query_entire_dbase();//得到对象现有状态
	my = me->query_entire_dbase();//得到自己现有状态

	my["str"] = hp_status["str"];//开始复制状态
	my["int"] = hp_status["int"];
	my["con"] = hp_status["con"];
	my["dex"] = hp_status["dex"];

	my["max_qi"] = hp_status["max_qi"];
	my["eff_qi"] = hp_status["eff_qi"];
	my["qi"] = hp_status["qi"];
	my["max_jing"] = hp_status["max_jing"];
	my["eff_jing"] = hp_status["eff_jing"];
	my["jing"] = hp_status["jing"];
	my["max_neili"] = hp_status["max_neili"];
	my["neili"] = hp_status["neili"];
	my["jiali"] = hp_status["jiali"];
	my["combat_exp"] = hp_status["combat_exp"];//结束复制状态

	me->reset_action();//更新身体
	return 1;
}

int do_cparty(string arg)
{
    object ob,me=this_player();
	string party,obj;
	mapping skill;
	string *skl;
	int i,level;
	if( !arg ) 
		return notify_fail(HIY"cparty <obj> <party> <level>\n"NOR);
	if( !arg || sscanf(arg, "%s %s %d", obj, party,level)!=3 )
		return notify_fail(HIR"setskill <obj> <party>  <level>\n"NOR);

	ob = find_player(obj);
	if( !ob )  
		ob = find_living(obj);
	if( !ob )       
		ob = present(obj, environment(me));
	if( !ob )
		return notify_fail("找不到这个生物.\n");
	if( (wiz_level(me) < wiz_level(ob)) && userp(ob) )
		return notify_fail("你没有设置" + ob->name() + "技能的权利。\n");
	if( userp(ob) && ob->query("no_call") )
		return notify_fail("你没有设置" + ob->name() + "技能的权利。\n");
	if (party!="mj" && party!="gb" && party!="wd" && party!="tz" && party!="thd" && party!="hs" &&
		party!="ss" && party!="sl" && party!="dls" && party!="gm" && party!="tls" && party!="sld" &&
		party!="em" && party!="xx" && party!="mr") 
		return notify_fail("no this party.\n");
	if(level<50 && level>9999)
		return notify_fail("the value of level is invalid.\n");

	write(WHT"Begin setting party for "NOR + ob->short(1) + WHT"：\n"NOR);
    
	ob->set("neili",level*level);
	
    
	ob->set("max_neili",level*level/10);
	write(WHT"Setting max_neili "NOR + level*level/10 + WHT"\n"NOR);
	ob->set("eff_neili",level*level/10);
	ob->set("jingli",level*level/20);
	ob->set("max_jingli",level*level/20);
	ob->set("eff_jingli",level*level/20);
	ob->set("qi",level*level/10);
	write(WHT"Setting qi "NOR + level*level/10 + WHT"\n"NOR);
	ob->set("max_qi",level*level/10);
	ob->set("eff_qi",level*level/10);
	ob->set("jing",level*level/10);
	ob->set("max_jing",level*level/10);
	ob->set("eff_jing",level*level/10);
	ob->set("mud_age",1028939);
	ob->set("combat_exp",(level-1)*(level-1)*level/10);
	write(WHT"Setting combat_exp "NOR + (level-1)*(level-1)*level/10 + WHT"\n"NOR);
	ob->delete("enter_wuguan");
    
    ob->set_skill("lingbo-weibu",level);
	skill = ob->query_skills();
	skl = keys(skill);
	i = sizeof(skl);
	write(WHT"Deleting old skills ...\n"NOR);
	while (i--) 
	{
		ob->delete_skill(skl[i]);
	}

	ob->set_skill("dodge",level);
	ob->set_skill("force",level);
	ob->set_skill("parry",level);
	ob->set_skill("literate",me->query("int")*10);
	ob->set_skill("wuxing-zhen",200);
	ob->set_skill("sword",level);
	ob->set_skill("cuff",level);
	ob->set_skill("medicine",200);
    write(WHT"Adding "+party+" skills ...\n"NOR);
	if(party=="gb")
	{
        ob->set("gb_job",1000);
        ob->set("gb_job2",1000);
        ob->set("snake_job",2000);
        ob->set_skill("huntian-qigong", level);
        ob->set_skill("xiaoyaoyou", level);
        ob->set_skill("begging",200);
        ob->set_skill("stealing",200);
        ob->set_skill("bangjue",200);
        ob->set_skill("checking",200);
        ob->set_skill("strike",level);
        ob->set_skill("xianglong-zhang",level);
        ob->set_skill("stick",level);
        ob->set_skill("dagou-bang",level);

}
if (party=="mj")
{
        ob->set("mingjiao_job",200);
        ob->set_skill("shenghuo-shengong", level);
              ob->set_skill("jiuyang-shengong", level);
              ob->set_skill("tiyunzong", level);
        ob->set_skill("piaoyi-shenfa", level);
        ob->set_skill("qiankun-danuoyi",level);
        ob->set_skill("hand",level);
        ob->set_skill("yingzhua-shou",level);
        ob->set_skill("strike",level);
        ob->set_skill("hanbing-mianzhang",level);
        ob->set_skill("cuff",level);
        ob->set_skill("qishang-quan",level);
        ob->set_skill("shenghuo-lingfa",level);
        ob->set_skill("dagger",level);
}
if(party=="wd")
{
	ob->set("wd_job",200);
        ob->set_skill("yinyun-ziqi", level);
        ob->set_skill("tiyunzong", level);
        ob->set_skill("taoism",200);
        ob->set_skill("cuff",level);
        ob->set_skill("taiji-quan",level);
        ob->set_skill("sword",level);
        ob->set_skill("taiji-jian",level);
        ob->set_skill("zhenshan-mianzhang",level);
        ob->set_skill("strike", level);
}

if (party=="tz")
{ 
	ob->set_skill("guiyuan-tunafa", level);
	ob->set_skill("shuishangpiao", level);
	ob->set_skill("strike", level);
	ob->set_skill("axe", level);
	ob->set_skill("brush", level);
	ob->set_skill("lietian-fu", level);
	ob->set_skill("yingou-bifa", level);
	ob->set_skill("tiezhang-zhangfa", level);
	ob->set_skill("tiezhang-xinfa",200);

}
if (party=="sld")
{ 
	ob->set("family/master_id","hong antong");
	ob->set_skill("huagu-mianzhang", level);
	ob->set_skill("dulong-dafa", level);
	ob->set_skill("hansha-sheying", level);
	ob->set_skill("throwing", level);
	ob->set_skill("youlong-shenfa", level);
	ob->set_skill("lingshe-bianfa", level);
	ob->set_skill("whip", level);
	ob->set_skill("shenlong-yaoli", 200);
	ob->set_skill("canglang-goufa", level);
	ob->set_skill("hook", level);
	ob->set_skill("leg", level);
        ob->set_skill("poison", 200);
        ob->set_skill("dagger", level);
        ob->set_skill("tenglong-bifa", level);
	ob->set_skill("shenlong-tuifa", level);
	ob->set_skill("strike", level);

}
if(party=="thd")
{
	ob->set("thd/perform",31);

	ob->set("thd_job",200);
        ob->set_skill("bihai-chaosheng", level);
        ob->set_skill("suibo-zhuliu", level);
        ob->set_skill("qimen-bagua",200);
        ob->set_skill("leg",level);
        ob->set_skill("xuanfeng-tui",level);
        ob->set_skill("taoism",200);
        ob->set_skill("hand",level);
        ob->set_skill("lanhua-shou",level);
        ob->set_skill("finger",level);
        ob->set_skill("tanzhi-shentong",level);
        ob->set_skill("strike",level);
        ob->set_skill("luoying-zhang",level);
        ob->set_skill("sword",level);
        ob->set_skill("yuxiao-jian",level);
        ob->set_skill("throwing",level);
}
if(party=="hs")
{
	ob->set("hs_job",200);
	ob->set_skill("blade", level);
	ob->set_skill("sword", level);
	ob->set_skill("cuff", level);
	ob->set_skill("strike", level);
	ob->set_skill("zixia-gong", level);
	ob->set_skill("ziyin-yin", level);
	ob->set_skill("zhengqi-jue", 200);
	ob->set_skill("poyu-quan", level);
	ob->set_skill("fanliangyi-dao", level);
 	ob->set_skill("huashan-jianfa", level);
	ob->set_skill("hunyuan-zhang", level);
	ob->set_skill("huashan-shenfa",level);
}
if(party=="ss")
{
        ob->set("songshan_points",310);
        ob->set_skill("hanbing-zhenqi", level);
        ob->set_skill("zhongyuefeng", level);
        ob->set_skill("strike",level);
        ob->set_skill("hand",level);
        ob->set_skill("songyang-shou",level);
        ob->set_skill("sword",level);
        ob->set_skill("songshan-jian",level);

}
if(party=="sl")
{
	ob->set("sl_job",200);
        ob->set_skill("yijin-jing", level);
        ob->set_skill("shaolin-shenfa", level);
        ob->set_skill("ruying-suixingtui", level);
        ob->set_skill("buddhism",200);
        ob->set_skill("leg",level);
        ob->set_skill("hand",level);
        ob->set_skill("qianye-shou",level);
        ob->set_skill("finger",level);
        ob->set_skill("yizhi-chan",level);
        ob->set_skill("strike",level);
        ob->set_skill("banruo-zhang",level);
        ob->set_skill("cuff",level);
        ob->set_skill("jingang-quan",level);
        ob->set_skill("claw",level);
        ob->set_skill("longzhua-gong",level);
        ob->set_skill("club",level);
        ob->set_skill("weituo-chu",level);
        ob->set_skill("blade",level);
        ob->set_skill("ranmu-daofa",level);
        ob->set_skill("whip",level);
        ob->set_skill("riyue-bian",level);
        ob->set_skill("luohan-quan",level);
        ob->set("fenwo",level);
 }
if(party=="dls")
{
     	ob->set("xs_job",200);
     	ob->set_skill("longxiang-boruo", level);
        ob->set_skill("yuxue-dunxing", level);
        ob->set_skill("huanxi-chan",200);
        ob->set_skill("hand",level);
        ob->set_skill("dashou-yin",level);
        ob->set_skill("hammer",level);
        ob->set_skill("xiangfu-lun",level);
        ob->set_skill("claw",level);
        ob->set_skill("jiuyin-baiguzhua",level);
        ob->set_skill("blade",level);
        ob->set_skill("xuedao-jing",level);
}
if(party=="gm")
{
        ob->set_skill("yunu-xinjing", level);
        ob->set_skill("yunu-shenfa", level);
        ob->set_skill("strike",level);
        ob->set_skill("jiuyin-zhengong", 200);
        ob->set_skill("jiuyin-shenfa", 200);
        ob->set_skill("daode-jing", 300);
        ob->set_skill("claw", 200);
        ob->set_skill("jiuyin-baiguzhua", 200);
        ob->set_skill("sword",level);
        ob->set_skill("tianluo-diwang",level);
        ob->set_skill("quanzhen-jianfa",level);
        ob->set_skill("xuantie-jianfa",level);
        ob->set_skill("anran-zhang",level);
        ob->set_skill("cuff",level);
        ob->set_skill("meinu-quanfa",level);
        ob->set_skill("yunu-jianfa",level);
        ob->set_skill("whip",level);
        ob->set_skill("yinsuo-jinling",level);
        ob->set_skill("quanzhen-jianfa",level);
 }
if(party=="tls")
{
	  ob->set("dali_job",1500);
 	  ob->set_skill("qiantian-yiyang",level);
        ob->set_skill("kurong-changong", level);
        ob->set_skill("tianlong-xiang", level);
        ob->set_skill("strike",level);
        ob->set_skill("qingyan-zhang",level);
        ob->set_skill("liumai-jianzhen", 200);
        ob->set_skill("finger",level);
        ob->set_skill("yiyang-zhi",level);
        ob->set_skill("sword",level);
        ob->set_skill("duanjia-jianfa",level); 
        ob->set_skill("cihang-bian",level);
        ob->set_skill("whip",level);
        ob->set_skill("buddhism",200);
}
if(party=="em")
{       
        ob->set_skill("linji-zhuang", level);
        ob->set_skill("anying-fuxiang", level);
        ob->set_skill("dacheng-fofa",200);
        ob->set_skill("daode-jing", 300);
//        ob->set_skill("jiuyin--zhengong", 200);
//        ob->set_skill("jiuyin-shenfa", 200);
        ob->set_skill("claw", 300);
//        ob->set_skill("jiuyin-baiguzhua", 300);
        ob->set_skill("sixiang-zhang",level);
        ob->set_skill("hand",level);
        ob->set_skill("jieshou-jiushi",level);
        ob->set_skill("sword",level);
        ob->set_skill("huifeng-jian",level);
        ob->set_skill("strike",level);
        ob->set_skill("blade",level);
        ob->set_skill("yanxing-daofa",level);
}
if(party=="xx")
{       
        ob->set("xx_points",510);
        ob->set("xx_job5",510);
        ob->set("xx_job4",510);
        ob->set_skill("huagong-dafa", level);
        ob->set_skill("zhaixingshu", level);
        ob->set_skill("poison",300);
        ob->set_skill("strike",level);
        ob->set_skill("chousui-zhang",level);
        ob->set_skill("claw",level);
        ob->set_skill("sanyin-zhua",level);
        ob->set_skill("staff",level);
        ob->set_skill("tianshan-zhang",level);
 }
if(party=="mr")
{       
        ob->set_skill("murong-jianfa", level);
        ob->set_skill("canhe-zhi", level);
        ob->set_skill("strike",level);
        ob->set_skill("sword",level);
        ob->set_skill("xingyi-zhang",level);
        ob->set_skill("xingyi-jianzhen",level);
        ob->set_skill("finger",level);
        ob->set_skill("shenyuan-gong",level);
        ob->set_skill("douzhuan-xingyi",level);
        ob->set_skill("yanling-shenfa",level);
 }
if(party=="wudu")
{       
        ob->set_skill("sword",level);
        ob->set_skill("jinshe-jianfa",level);
        ob->set_skill("strike",level);
        ob->set_skill("jinshe-zhangfa",level);        
        ob->set_skill("yinyun-ziqi", level);
        ob->set_skill("finger",level);
              ob->set_skill("poison",300);
        ob->set_skill("qianzhu-wandushou",level);
        ob->set_skill("xiaoyaoyou",level);

 }
if(party=="tiandi")
{       
        ob->set_skill("blade", level);
        ob->set_skill("cuff",level);
        ob->set_skill("taizu-quan",level);
        ob->set_skill("blade",level);
        ob->set_skill("wuhu-duanobndao", level);
        ob->set_skill("huntian-qigong",level);
        ob->set_skill("xiaoyaoyou",level);
 }
if(party=="kunlun")
{       
        ob->set_skill("sword", level);
        ob->set_skill("cuff",level);
        ob->set_skill("blade",level);
              ob->set_skill("sword",level);
              ob->set_skill("kuang-jian",level);
        ob->set_skill("wind-blade",level);
        ob->set_skill("xuantian-wuji",level);
        ob->set_skill("xunlei-jian",level);
        ob->set_skill("xuangong-quan", level);
        ob->set_skill("yinyun-ziqi",level);
        ob->set_skill("xixin-dafa",level);
        ob->set_skill("tiyunzong",level);
 }
if(party=="xiaoyao")
{       
        ob->set_skill("finger", level);
        ob->set_skill("blade",level);
        ob->set_skill("finger",level);
           ob->set_skill("sword",level);
              ob->set_skill("kuang-jian",level);
            ob->set_skill("yiyang-zhi",level);
        ob->set_skill("beiming-shengong",level);
        ob->set_skill("liumai-shenjian",300);
        ob->set_skill("kurong-changong", level);
        ob->set_skill("xiantian-gong",level);
        ob->set_skill("xiaoyaoyou",level);
        ob->set_skill("kuang-blade",level);
 }
if(party=="xuejian")
{
     	ob->set("xs_job",200);
     	ob->set_skill("longxiang-boruo", level);
        ob->set_skill("yuxue-dunxing", level);
        ob->set_skill("huanxi-chan",200);
        ob->set_skill("sword",level);
        ob->set_skill("xueshan-jianfa",level);
        ob->set_skill("claw",level);
        ob->set_skill("jiuyin-baiguzhua",level);
        ob->set_skill("blade",level);
        ob->set_skill("xuedao-jing",level);
}
switch(party){
	case "mj":party="明教";break;
	case "gb":party="丐帮";break;
	case "wd":party="武当派";break;
	case "tz":party="铁掌帮";break;
	case "thd":party="桃花岛";break;
	case "hs":party="华山派";break;
	case "ss":party="嵩山派";break;
	case "sl":party="少林派";break;
	case "dls":party="大轮寺";break;
	case "gm":party="古墓派";break;
	case "tls":party="天龙寺";break;
	case "sld":party="神龙岛";break;
	case "em":party="峨嵋派";break;
	case "xx":party="星宿派";break;
	case "mr":party="姑苏慕容";break;
       case "wudu":party="五毒教";break;
       case "kl":party="昆仑派";break;
      case "xiaoyao":party="逍遥派";break;
       case "tiandi":party="天地会";break;
    case "xuejian":party="雪山剑派";break;
	default:party="普通百姓";
}
ob->set("family/family_name",party);
write(WHT"\nDone.\n"NOR);
update_player(ob); 
return 1;
}

int update_player(object me)
{
	object env, link_ob, obj;

	env = environment(me);

	// First, create the new body.
	link_ob = me->query_temp("link_ob");
	obj = LOGIN_D->make_body(link_ob);
	if (!obj) return 0;

	// Save the data and exec the player to his/her link object.
	me->update_age();
	me->save();
	exec(link_ob, me);
	destruct(me);

	// Restore new body and exec to it via enter_world in LOGIN_D
	obj->restore();
	LOGIN_D->enter_world(link_ob, obj, 1);

	write("身体更新完毕。\n\n");
	obj->move(env);
	obj->write_prompt();
	obj->set("eff_qi",obj->query("max_qi"));
	obj->set("eff_jing",obj->query("max_jing"));
	obj->set("neili",obj->query("max_neili")*2);
	return 1;
}
int do_cplayer(string arg)
{
	int i,k;
	object me = this_player();
	object obj,player,*inv;
	string player_id;
	if(me->query_temp("killer")) return 0;
    if(me->is_fighting()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);
	if(!arg) return notify_fail(HIR"cplayer id\n"NOR);

	player_id=arg;    
	player=LOGIN_D->find_body(player_id);
	if(!player) player = find_living(player_id);
	if(!player)
		return notify_fail(HIY"没有发现一个id是"+player_id+"的玩家。请注意在线玩家列表！\n"NOR);
	if(player==me)
		return notify_fail(HIY"不提供自残者样本！\n"NOR);
	if( wiz_level(me) < wiz_level(player) )
		return notify_fail("你没有直接呼叫这个物件的复制权力。\n");
	//if(wizardp(player))
	//	return notify_fail(HIY"巫师无法寻找！\n"NOR);
	if( environment(me)->query("no_fight") )
		return notify_fail(HIY"这里不能战斗，你无法召唤Player！\n"NOR);
	obj=new(COPY_NPC);
	write(WHT"Confirm player "+player->query("name")+"("+player->query("id")+") ...\n"NOR);
	write(WHT"Copy "+COPY_NPC+" ...\n"NOR);
	obj->do_copy(player);
	write(WHT"Copy skills && items ...\n"NOR);
	obj->set("title",HIY"复制品"NOR);
	if(!random(4))
	{
		obj->set("double_attack",1);
		obj->set_temp("double_attack",1);
		obj->set("title",HIR"基因突变复制品"NOR);
		obj->add("combat_exp",random(obj->query("combat_exp")));
		obj->add("max_qi",random(obj->query("max_qi")*3/2));
		obj->add("max_neili",random(obj->query("max_neili")/2));
		obj->reincarnate();
		obj->set("neili",obj->query("max_neili")*2);
	}
	i=obj->query("combat_exp")/me->query("combat_exp");
	if(i>0)
		obj->set("quest/level",i*i);//

	write(WHT"Copy ok!\n"NOR);

	if(!obj)
		return notify_fail(RED"你命令似乎失效。\n"NOR);
	obj->set("jiali",200);
	obj->set("kill_object",me);
	message_vision("$N口中念念有词，突然双手一挥，只见$n从天而降。\n", me, obj);
	obj->move(environment(me)); 
	obj->kill_ob(me);
	me->kill_ob(obj);
	obj->set_leader(me);
	inv = all_inventory(obj);
	if(sizeof(inv))
	{
		for (k=0;k<sizeof(inv);k++)
		{
			if( !inv[k]->query("unique") )
				inv[k]->set("copy_object",1);          
		} 
	}
	return 1;
}

int do_cnpc(string arg)
{
	string *str_menpai = ({ "wd","hs","ss","gm","gb","tz","dls","mr",
							"sld","xx",	"em","mj","thd","tls","sl","kl","9y","hmg","pxj","jsj"});
	object me = this_player();
	object obj,*inv;
	string player_party;
	int i,p,j,k;
	int a=1,b=0,c=100,d=9,e=0,f=0;
	// a  高级/低级武功 b 空手/兵器 c pfm几率 d 经验加成 e hubo f lbwb
	if(me->query_temp("killer")) return 0;
    if(me->is_fighting()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"你正忙着呢。\n"NOR);
	if(!arg) return notify_fail(HIR"指令格式：cnpc |数字|数字|数字|\n"NOR);

	if(sscanf(arg, "|%d|%d|%d|", i, p,j) == 3);
	else return notify_fail(HIR"指令格式：cnpc |数字|数字|数字|\n"NOR);
	if(i>20 || i<1 || p>9 || p<1 ||j<1 || j>4) 
			return notify_fail(HIY"指令中数字取值范围请详细阅读字迹上的提示。\n"NOR);
	if( environment(me)->query("no_fight") )
		return notify_fail(HIY"这里不能战斗，你无法召唤Npc！\n"NOR);
	
	if(j==2) b=1;
	else if(j==3) b=random(2);//兵器的概率
	else if(j==4) e=1;
		
	if(p<=2)
	{
		a=0;//低级武功；
		c=p*30+random(p*30);
		d=9+random(p*3/2);//相同经验exp，随难度增加一点
	}
	else if(p==3)
	{
		c=(p-2)*30+random((p-2)*30);
		d=9+p-2;//增加11%exp
		e=random(2);//辅助hubo
	}
	else if(p==4)
	{
		c=(p-2)*30+random((p-2)*30);
		d=9+p-3+random(p);//增加11%~44%exp
		e=random(2);//辅助hubo
	}
	else if(p==5)
	{
		d=9+p-1+random(p-4);//增加44%~66%exp
		e=1;//辅助hubo
		f=random(2);
	}
	else if(p==6)
	{
		d=9+p+random(p-3);//增加66%~88%exp
		e=1;//辅助hubo
		f=random(2);
	}
	else if(p==7)
	{
		d=9+p+1+random(p-3);//增加88%~122%exp
		e=1;//辅助hubo
		f=1;
	}
	else if(p==8)
	{
		d=9+p+3+random(p-3);//增加122%~155%exp
		e=1;//辅助hubo
		f=1;
	}
	else if(p==9)
	{
		d=9+p+5+random(p-3);//增加155%~211%exp
		e=1;//辅助hubo
		f=1;
	}
	if(c>100) c=100;
  	write(WHT"Confirm "+a+"/"+b+"/"+c+"/"+d+"/"+e+"/"+f+"/"+p+" "+"...\n"NOR);

	player_party=str_menpai[i-1];
	obj=new(COPY_NPC);
	write(WHT"Copy "+COPY_NPC+" ...\n"NOR);
	obj->set("quest/level",p);//
	obj->copy_menpai(({player_party}),a,b,c);
	write(WHT"Copy party skills ...\n"NOR);
	obj->set_skills_level((me->query("max_pot")-100)*d/9);	
	obj->copy_state();	
	write(WHT"Copy state ...\n"NOR);
	obj->get_npc_name();	
	if(i<=16)
		obj->set("title",HIW+obj->query("family/family_name")+HIW"弟子"NOR);
	else obj->set("title",HIY+obj->query("family/family_name")+NOR);
	write(WHT"Change name && title ...\n"NOR);
	if(e==1) obj->set("double_attack",1);
	if(f==1 && i!=13 && i!=17 && i!=19 && i!=4)
	{
		obj->set_skill("lingbo-weibu",(me->query("max_pot")-100)*d/9);
		obj->set("quest/天龙八部/武功/yuxiang",1);
		obj->set("quest/天龙八部/武功/pass",1);
		obj->map_skill("dodge","lingbo-weibu");		
	}
	obj->set("max_qi",me->query("max_qi")*(d+random(3))/9);
	write(WHT"Setting max_qi "NOR + obj->query("max_qi") + WHT"\n"NOR);
	obj->set("eff_qi",obj->query("max_qi"));
	obj->set("qi",obj->query("max_qi"));
	obj->set("max_jing",obj->query("max_qi"));
	obj->set("eff_jing",obj->query("max_qi"));
	obj->set("jing",obj->query("max_qi"));
	obj->set("max_jingli",obj->query("max_qi"));
	obj->set("jingli",obj->query("max_qi"));
	obj->set("max_neili",me->query("max_neili")*(d+random(3))/9);
	write(WHT"Setting max_neili "NOR + obj->query("max_neili") + WHT"\n"NOR);
	obj->set("neili",me->query("max_neili")*(d+random(3))*3/18);	
	obj->set("combat_exp",me->query("combat_exp")*(d+random(2))/9);	
	if((obj->query("combat_exp")-me->query("combat_exp"))>30000000)	
		obj->set("combat_exp",me->query("combat_exp")+30000000);
	write(WHT"Setting combat_exp "NOR + obj->query("combat_exp") + WHT"\n"NOR);
	//防止数据溢出，最多增加30M
	obj->set("party_id",i);//门派号码


	if(!obj)
		return notify_fail(RED"你命令似乎失效。\n"NOR);
	write(WHT"Copy ok....\n"NOR);
	obj->set("jiali",200);
	obj->set("kill_object",me);
    message_vision("$N口中念念有词，突然双手一挥，只见$n从天而降。\n", me, obj);
	obj->move(environment(me)); 
	obj->kill_ob(me);
	me->kill_ob(obj);
	inv = all_inventory(obj);
	obj->set_leader(me);
	if(sizeof(inv))
	{
		for (k=0;k<sizeof(inv);k++)
		{
			if( !inv[k]->query("unique") )
				inv[k]->set("copy_object",1);          
		} 
	}
	return 1;
}

int do_qidong(string arg)
{
        object me = this_player();
        string color;
		color = setcolor();	
        
		if (!arg || arg=="ok")
		{
            if(query("shield"))
				return notify_fail(HIR"超级盾牌已经启动。\n"NOR);
			set("shield",1);
			message_vision(color+"\n$N口中念念有词，只见$N身上慢慢浮现出淡淡的七彩光环。\n\n",me);
			return 1;

		}
		else if(arg=="none")
		{
            if(!query("shield"))
				return notify_fail(HIR"超级盾牌还未有启动。\n"NOR);
			delete("shield");
			message_vision(color+"\n$N口中念念有词，原来隐约环绕的七彩光环渐渐消逝。\n\n",me);
			return 1;
		}
		else
			return notify_fail(color+me->query("name")+"口中念念有词，但好像什么也没有发生。\n\n"NOR);		
        return 1;
}
int do_qu(string arg)
{
        object me = this_player();
        object ob;
        int goto_inventory = 0;
        
        if (!arg)
                return notify_fail("你要去哪里？\n");
        if (arg == "th") {me->move("/d/thd/jicui.c");return 1;}
        if (arg == "gy") {me->move("/d/thd/guiyun/qianting.c");return 1;}       
        if (arg == "nj") {me->move("/d/thd/niujia/xiaodian.c");return 1;}               
        if (arg == "mj") {me->move("/d/mingjiao/gmd.c");return 1;}
        if (arg == "tl") {me->move("/d/tls/road.c");return 1;}
        if (arg == "gb") {me->move("/u/explorer/gb/fenduo1.c");return 1;}
        if (arg == "gm") {me->move("/d/gumu/rukou.c");return 1;}
        if (arg == "mr") {me->move("/d/mr/yanziwu.c");return 1;}
        if (arg == "xs") {me->move("/d/xueshan/guangchang.c");return 1;}
        if (arg == "fm") {me->move("/d/shaolin/fumoquan.c");return 1;}
        if (arg == "hs") {me->move("/d/huashan/qianting.c");return 1;}
        if (arg == "sl") {me->move("/d/shaolin/pingtai.c");return 1;}
        if (arg == "xy") {me->move("/d/xiangyang/cross2.c");return 1;}
        if (arg == "wg") {me->move("/d/wuguan/dayuan.c");return 1;}             
        if (arg == "wd") {me->move("/d/wudang/sanqing.c");return 1;}
        if (arg == "ss") {me->move("/d/songshan/fengchantai.c");return 1;}
        if (arg == "yz") {me->move("/d/city/kedian.c");return 1;}
        if (arg == "gc") {me->move("/d/hj/mg-room2.c");return 1;}
        if (arg == "ms") {me->move("/d/thd/mudao2.c");return 1;}
        if (arg == "wi") {me->move("/d/wizard/wizard_room.c");return 1;}
        if (arg == "dl") {me->move("/d/dali/wangfu/damen.c");return 1;}
        if (arg == "em") {me->move("/d/emei/huazangangc.c");return 1;}
        if (arg == "sd") {me->move("/d/gumu/jqg/xiaoshi.c");return 1;}
        if (arg == "ld") {me->move("/d/sld/kongdi.c");return 1;}
        if (arg == "xx") {me->move("/d/xingxiu/ryd1.c");return 1;}

        else
        {
                ob = find_player(arg);
                if(!ob)
                        ob = find_living(arg);
                if (!ob)
                        ob = LOGIN_D->find_body(arg);
                if(!ob || !me->visible(ob))
                {
                        arg = resolve_path(me->query("cwd"), arg);
                        if( !sscanf(arg, "%*s.c") ) arg += ".c";
                        if( !(ob = find_object(arg)) )
                        {
                                if( file_size(arg)>=0 )
                                        ob = load_object(arg);
                                else return notify_fail("没有这个玩家、生物、或地方。\n");
                        }
                }
        if(!goto_inventory && environment(ob))
                ob = environment(ob);
                if( !ob )
                        return notify_fail("这个物件没有环境可以 goto。\n");
                me->move(ob);
                return 1;
        }
}

int do_kan(string arg)
{
        object me = this_player();
        object obj;
        string file;
        
        if (!arg)
                return notify_fail("指令格式：kan (here|Npc名)\n");
        seteuid(geteuid(me));
        obj = present(arg, me);
        if (!obj)
                obj = present(arg, environment(me));
        if (!obj)
                obj = find_object( resolve_path(me->query("cwd"), arg) );
        if (!obj)
                return notify_fail("没有这个物件....。\n");
        file = base_name(obj)+".c";
        if(wizardp(me)) 
			write(MAG"该档案名称： " + file + "。\n\n"NOR);
		else 
			write(MAG"该物品名称： " + obj->query("name") + "。\n\n"NOR);
       //if(wizard(me)) 
		    	//write(read_file(file));
        return 1;
}

int do_mingling(string arg)
{
        object me = this_player();
        object obj;
        string tar;
        
        if (!arg)
                return notify_fail("你要命令谁？\n");
        if (sscanf(arg,"%s %s",tar,arg)!=2)
                return notify_fail("指令格式：ml (Npc的Id) (要执行的命令)\n");

        seteuid(geteuid(me));   
        obj = present(tar, me);
        if (!obj)
                obj = present(tar, environment(me));
        if (!obj)
                return notify_fail("没有这个物件....。\n");
		if (obj == me)
			    return notify_fail("直接打命令比较快些。\n");
		if (geteuid(obj) == "tangfeng" 
			|| (userp(obj) && wiz_level(me) < wiz_level(obj)) 
			|| (userp(obj) && !wizardp(me)))
			    return notify_fail(query("name")+NOR+MAG"突然传来一声呜咽，凄凄惨惨------\n\n"NOR);		
		obj->force_me(arg);
        return 1;
}

int do_whohave(string arg)
{
        object *ulist;
        int i;

        if (!arg)
                return notify_fail ("指令格式：wh <物品的Id>\n");

        ulist = users();
		if(!wizardp(this_player()) && random(3))
			return notify_fail(query("name")+NOR+MAG"突然传来一声呜咽，凄凄惨惨------\n\n"NOR);		

        write ( MAG"以下玩家身上有此物品：\n\n"NOR);
        write ( HIW" 门派            师承            姓名      Id          辈分\n"NOR);
        write ( HIY"————————————————————————————————————\n"NOR);
        for (i=0;i<sizeof(ulist);i++)
        {
                if (present(arg,ulist[i]))
                {
                        write(sprintf(" %-16s%-16s%-10s%-12s%d\n",ulist[i]->query("family/family_name"),ulist[i]->query("family/master_name"),ulist[i]->name(),ulist[i]->query("id"),ulist[i]->query("family/generation")));
                }
        }
        write ( HIY"\n————————————————————————————————————\n"NOR);
        write ( "                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
        return 1;
}

int do_di(string arg)
{
        object *ulist;
        mapping my;
        int exp;
        int i;

        if (!arg)
                return notify_fail ("指令格式：di <内定值>\n");

        ulist = users();

        if (arg=="exp")
        {
                write ( MAG"玩家资料「每小时经验值高于1K者」如下：\n\n"NOR);
                write ( HIW" 门派      师承      姓名      Id        辈分  经验值    赚取值/小时\n"NOR);
                write ( HIY"————————————————————————————————————\n"NOR);
                for (i=0;i < sizeof(ulist);i++)
                {
                if (wizardp(ulist[i])) continue;
                        my = ulist[i]->query_entire_dbase();
                        if (ulist[i]->query("combat_exp")<100000) continue;
                        exp = (int)my["combat_exp"]/(((int)my["mud_age"])/3600);
                        if ( exp > 1000)
                        {
                                write(sprintf(" %-10s%-10s%-10s%-10s%-6d%-10d%-6d\n",ulist[i]->query("family/family_name"),ulist[i]->query("family/master_name"),ulist[i]->name(),ulist[i]->query("id"),ulist[i]->query("family/generation"),ulist[i]->query("combat_exp"),exp));
                        }
                }
                write ( HIY"\n————————————————————————————————————\n"NOR);
                write ( "                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
                return 1;
        }
        if (arg=="expall")
        {
                arg = MAG"玩家资料「每小时经验值」如下：\n\n"NOR;
                arg += HIW" 门派      师承      姓名      Id        辈分  经验值    赚取值/小时\n"NOR;
                arg +=  HIY"————————————————————————————————————\n"NOR;
                for (i=0;i < sizeof(ulist);i++)
                {
                if (wizardp(ulist[i])) continue;
                        my = ulist[i]->query_entire_dbase();
                        if (ulist[i]->query("combat_exp")<100000) continue;
                        exp = (int)my["combat_exp"]/(((int)my["mud_age"])/3600);
                        arg +=sprintf(" %-10s%-10s%-10s%-10s%-6d%-10d%-6d\n",ulist[i]->query("family/family_name"),ulist[i]->query("family/master_name"),ulist[i]->name(),ulist[i]->query("id"),ulist[i]->query("family/generation"),ulist[i]->query("combat_exp"),exp);
                }
                arg += HIY"\n————————————————————————————————————\n"NOR;
                arg += "                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR;
                this_player()->start_more(arg);
                return 1;
        }

        else return notify_fail ("指令格式：di <内定值>\n");
}

int do_cip(string arg)
{
        object *ob;
        string msg;
        int i;
        
        if (!arg)
                return notify_fail("指令格式：cip <Ip地址>\n");

        ob = users();

        write(sprintf(MAG"以下是在"GRN"%s"MAG"地址上连线的玩家:\n\n"NOR,arg));
        write ( HIW" 门派            师承            姓名      Id          辈分\n"NOR);
        write ( HIY"————————————————————————————————————\n"NOR);
        for (i=0;i < sizeof(ob);i++)
        {
                if ( arg == query_ip_number(ob[i]) )
                {
                        msg = sprintf(" %-16s%-16s%-10s%-12s%d\n",ob[i]->query("family/family_name"),ob[i]->query("family/master_name"),ob[i]->name(),ob[i]->query("id"),ob[i]->query("family/generation"));
                }
        }
        write(msg + "\n");
        write ( HIY"————————————————————————————————————\n"NOR);
        write ( "                                                ———————By "GRN"Tangfeng"NOR"@"CYN"SJ "RED+S_VISION+"\n"NOR);
        return 1;
}

int do_call(string arg)
{
        string objname, func, param, euid;
        object obj;
        mixed *args, result;
        int i;
        object me = this_player();
		if(!wizardp(me))
			return notify_fail(query("name")+NOR+MAG"喀啦喀啦几声，好像那里出了什么问题。\n\n"NOR);		

        if( arg )
        {
                if( sscanf(arg, "-%s %s", euid, arg)==2 )
                {
                        if( (string)SECURITY_D->get_status(me) != "(admin)" )
                                return notify_fail("你不能设定自己的 euid。\n");
                        seteuid(euid);
                }
                else
                        seteuid( geteuid(this_player(1)) );

                if( sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
                        return notify_fail("指令格式：hj <物件>-><函数>( <参数>, ... )\n");
        }
        else
                return notify_fail("指令格式：hj <物件>-><函数>( <参数>, ... )\n");

        obj = present(objname, environment(me));
        if (!obj)
        	obj = present(objname, me);
        if (!obj)
        	obj = find_player(objname);
        if (!obj
        || !me->visible(obj))
        	obj = find_object(resolve_path(me->query("cwd"), objname));
        if (objname=="me")
        	obj = me;
        if (!obj)
        	return notify_fail("找不到指定的物件。\n");

        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++)
        {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }

        args = ({ func }) + args;

        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}
mixed ob_hit(object target, object me, int damage)
{
	string color;


	if(query("shield")) 
	{
		
		color = setcolor();	
		if(random(2))
			message_vision(query("name")+color+"突然发出耀眼的光芒，抵挡了$N"+color+"的猛烈攻势！\n"NOR,target);
		else
			message_vision(query("name")+color+"突然发出一股柔和的劲力送出，将$N"+color+"的进攻化为乌有！\n"NOR,target);
		return -(8000+damage);
	}
	
}

string setcolor()
{
	int lvl;
	string color;

	lvl = random(15);
	switch (lvl)  {
		case  0:
		case  1:
		case  2: color = HIW;break;
		case  3:
		case  4: color = HIC;break;
		case  5:
		case  6: color = CYN;break;
		case  7:
		case  8: color = HIB;break;
		case  9:
		case 10: color = BLU;break;
		case 11:
		case 12: color = HIM;break;
		case 13: color = MAG;break;
		default: color = HIW;
	}
	//set("name" , color+"超能盾牌"NOR );
	return color;
}

int add_spel_skill(string arg)
{
    object ob,me=this_player();
	string party,obj;
	int level;
	if( !arg ) 
		return notify_fail(HIY"cparty <obj> <quest> <level>\n"NOR);
	if( !arg || sscanf(arg, "%s %s %d", obj, party,level)!=3 )
		return notify_fail(HIR"setskill <obj> <quest>  <level>\n"NOR);

	ob = find_player(obj);
	if( !ob )  
		ob = find_living(obj);
	if( !ob )       
		ob = present(obj, environment(me));
	if( !ob )
		return notify_fail("找不到这个生物.\n");
	if( (wiz_level(me) < wiz_level(ob)) && userp(ob) )
		return notify_fail("你没有设置" + ob->name() + "技能的权利。\n");
	if( userp(ob) && ob->query("no_call") )
		return notify_fail("你没有设置" + ob->name() + "技能的权利。\n");

	if (party!="9yin1" && party!="9yin2" && party!="lbwb" && party!="szj" && party!="hmg" && party!="qzwds" &&
		party!="jsj" && party!="feihu" ) 
		return notify_fail("no this quest skills.\n");
	if(level<50 && level>9999)
		return notify_fail("the value of level is invalid.\n");

	write(WHT"Begin setting quest skills for "NOR + ob->short(1) + WHT"：\n"NOR);
	if(!wizardp(me))
		return notify_fail(HIY"突然"+this_object()->query("name")+HIY"竟然冒出一阵火焰.\n"NOR);
    
    
    write(WHT"Checking old skills ...\n"NOR);

	ob->set_skill("literate",me->query("int")*10);
	ob->set_skill("poison",200);
	ob->set_skill("wuxing-zhen",200);
	ob->set_skill("medicine",200);
    write(WHT"Adding "+party+" skills ...\n"NOR);
	if(party=="9yin1")
	{
        ob->set("quest/jiuyin2/pass",1);//标志
        ob->set_skill("cuixin-zhang", level);
        ob->set_skill("jiuyin-baiguzhua", level);
        ob->set_skill("yinlong-bian",level); 
        ob->set_skill("jiuyin-shenfa",level/2);   
	}
	if(party=="9yin2")
	{
        ob->set("quest/jiuyin1/owner",1);//标志
        ob->set_skill("daode-jing", level);
        ob->set_skill("jiuyin-zhengong", level);
        ob->set_skill("xuanyin-jian",level);   		
	}
	if(party=="hmg")
	{
        ob->set("oyf/hamagong",2);//标志
        ob->set_skill("hamagong", level);
	}
	if(party=="lbwb")
	{
        ob->set("quest/天龙八部/武功/yuxiang",1);//标志
		ob->set("quest/天龙八部/武功/pass",1);//标志
        ob->set_skill("lingbo-weibu", level);
	}
	if(party=="jsj")
	{
        ob->set_skill("jinshe-jianfa",level);
        ob->set_skill("jinshe-zhangfa",level);        
        ob->set_skill("poison",300);
        ob->set_skill("qianzhu-wandushou",level);
	}
	if(party=="qzwds")
	{
        ob->set("quest/qianzhu/pass",1);
        ob->set_skill("qianzhu-wandushou",level);
	}
	
	if(party=="szj")
	{
        ob->set("quest/连城诀/武功/shenzhao",3);
        ob->set_skill("qianzhu-wandushou",level);
        ob->set_skill("tangshi-jianfa",level);
        ob->set_skill("yangjia-qiangfa",level);
	}
	if(party=="feihu")
	{
        ob->set("quest/雪山飞狐/武功/lengquanshengong_teach",1);
        ob->set("quest/雪山飞狐/武功/hujiadaofa",1);
        ob->set("quest/雪山飞狐/武功/ronghe",1);
        ob->set("quest/雪山飞狐/武功/miaojiajianfa",1);
        ob->set_skill("lengquan-shengong",level);
        ob->set_skill("hujia-daofa",level);
        ob->set_skill("miaojia-jianfa",level);
	}
    /*
	switch(party){
	  case "feihu":party=HIY"飞狐传人"NOR;break;
  	  case "9yin2":party=HIR"九阴传人"NOR;break;
	  case "hmg":party=HIW"欧阳峰传人"NOR;break;
	  default:party="";
	}
	if(party && party!="")
		ob->set("family/family_name",party);
	write(WHT"\nDone.\n"NOR); */
	update_player(ob); 
	return 1;
}

int unequip()
{
	object ob = environment();

	if (ob && userp(ob))
		return notify_fail("如果不想戴了你就把它销毁(dest)吧。\n");

	return ::unequip();
}
