//    空明拳


inherit SKILL;

#include <ansi.h>

mapping *action = ({
([
	"action" : WHT"$N使出「"HIC"空"WHT"」字诀，单拳击出，拳式若有若无，似乎毫无着力处，却又径直袭向$n"NOR,
	"lvl" : 0,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "空字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIY"朦"WHT"」字诀，拳招胡里胡涂，看似不成章法，但拳势却直指$n的$l"NOR,
	"lvl" : 10,
  "force" : 185,
  "dodge" : 15,
	"skill_name" : "朦字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIB"洞"WHT"」字诀，单拳似乎由洞中穿出，劲道内敛，招式却咄咄逼人，狠狠地击向$n"NOR,
	"lvl" : 20,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "洞字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIG"松"WHT"」字诀，出拳浑似无力，软绵绵地划出，轻飘飘地挥向$n的$l"NOR,
	"lvl" : 30,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "松字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIM"风"WHT"」字诀，单拳击出，带起一股柔风，$n刚觉轻风拂体，拳招竟已袭到了面前"NOR,
	"lvl" : 40,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "风字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIW"通"WHT"」字诀，拳力聚而不散，似有穿通之形，直击$n的$l"NOR,
	"lvl" : 50,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "通字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"MAG"容"WHT"」字诀，拳走空明，外包内容，似轻实重，正对着$n当胸而去"NOR,
	"lvl" : 60,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "容字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIM"梦"WHT"」字诀，拳势如梦，又在半梦半醒，$n一时神弛，拳风已然及体"NOR,
	"lvl" : 70,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "梦字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIY"冲"WHT"」字诀，单拳直击，拳式举重若轻，向$n的$l打去"NOR,
	"lvl" : 80,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "冲字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"YEL"穷"WHT"」字诀，正显潦倒之形，拳势虽然显出穷途末路，却暗含杀机，窥$n不备而猛施重拳"NOR,
	"lvl" : 90,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "穷字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIC"中"WHT"」字诀，单拳缓缓击出，不偏不倚，虽是指向正中，拳力却将$n的周身笼住"NOR,
	"lvl" : 100,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "中字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIB"弄"WHT"」字诀，拳招陡然花俏，似在作弄$n，却又暗伏后招"NOR,
	"lvl" : 110,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "弄字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIY"童"WHT"」字诀，出拳如稚童般毫无章法，胡乱击向$n的$l"NOR,
	"lvl" : 120,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "童字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIR"庸"WHT"」字诀，单拳击出时是最简单的招式，平平无奇，可是却阻住了$n的退路"NOR,
	"lvl" : 130,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "庸字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIG"弓"WHT"」字诀，身体弯曲如弓，拳出似箭，迅捷地袭向$n"NOR,
	"lvl" : 140,
	"force" : 185,
  "dodge" : 15,
	"skill_name" : "弓字诀",
	"damage_type" : "瘀伤"
]),
([
	"action" : WHT"$N使出「"HIW"虫"WHT"」字诀，身子柔软如虫，拳招也随着蠕动，$n竟无法判断这一拳的来势"NOR,
	"lvl" : 150,
  "force" : 185,
  "dodge" : 15,
	"skill_name" : "虫字诀",
	"damage_type" : "瘀伤"
]),
});

int valid_enable(string usage)
{
        if ( this_player()->query("quest/jiebai/pass") || this_player()->query("family/family_name") == "全真教"  )
		return usage=="cuff" || usage=="parry"; 
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("学空明拳必须空手。\n");
        if (!me->query("quest/jiebai/pass") && me->query("family/family_name") != "全真教" )
                return notify_fail("你既没和周伯通结义，又不是他徒弟，如何能学空明拳。\n");
	if (me->query("max_neili") < 1000) 
		return notify_fail("你的内力不够。\n");
	if (me->query_skill("force", 1) < 40)
		return notify_fail("你的内功火候不够，无法学空明拳。\n");
	if (me->query("max_neili") < 250)
		return notify_fail("你的内力太弱，无法练空明拳。\n");
	return 1;
}

string query_skill_name(int level)
{
       int i;
       for(i = sizeof(action)-1; i >= 0; i--)
               if(level >= action[i]["lvl"])
                       return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
       int i, level;
       level = (int)me->query_skill("kongming-quan", 1);
       for(i = sizeof(action); i > 0; i--)
               if(level > action[i-1]["lvl"])
                       return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	int lvl = me->query_skill("kongming-quan", 1);
	int i = sizeof(action);
	mapping learned = me->query_learned();

	if (!mapp(learned)) learned = ([]);
	if (!learned["kongming-quan"])
		while (i--) 
			if (lvl == action[i]["lvl"])
				return notify_fail("你将已经学会的所有招式练习了一遍，发现如果不去找老顽童学新的招式就无法获得进步了。\n");

	if ( me->query("jingli") < 60)
		return notify_fail("你的体力太低了。\n");
	if ( me->query("neili") < 30)
		return notify_fail("你的内力不够练空明拳。\n");
	me->receive_damage("jingli", 50);
	me->add("neili", -20);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"kongming-quan/" + action;
}

int ob_hit(object ob, object me, int damage)
{
  int i=me->query_skill("kongming-quan",1);
	if(me->query_skill_prepared("cuff")!= "kongming-quan"
	|| me->query_skill_mapped("parry") != "kongming-quan"
	|| me->query_temp("weapon")) 
		return 0;

	if ( me->query_temp("fanzhen")) {
		me->delete_temp("fanzhen");
		return 0;
	}
	if(random(me->query("dex")) > ob->query("dex", 1)/2){
       if(random(i)>(int)ob->query_skill("parry",1) /5
        &&!ob->query_temp("must_be_hit")
        &&!ob->query_condition("no_fight")){
            message_vision(HIB"$n被$N的气势所震慑，身法一滞，顿时连连中招！\n"NOR,me,ob);
            ob->set_temp("must_be_hit",1);
            call_out("yqq_must_be_hit",2,me,ob,random(i/50));
       }
   }
if(i<=220){
       if(random(i)>(int)ob->query_skill("dodge",1)/5
        &&!ob->query_temp("must_be_hit")
        &&!ob->query_condition("no_fight")){
            message_vision(HIW"$N拳劲回收，招数似已用老，陡然间双手横直互易，又是一拳向$n直击而出。！\n"NOR,me,ob);
            ob->set_temp("no_fight",1);
            ob->apply_condition("no_fight",1);
       }
   }
   
	if (me->query_temp("kongming/kong")
	&& random(me->query_skill("parry")) > ob->query("force", 1)/3
	&& !random(3)) {
		me->set_temp("fanzhen", 1);
		if( ob->query_skill_prepared("cuff")=="taiji-quan" 
			&& !ob->query_temp("weapon") 
			&& ob->query("family/family_name")=="武当派" ) {
			message_vision( HIW"$N潜运“空”字诀，想要化去对方的大力，不提防$n劲力轻柔无比，"
				+"以虚击虚，竟然打在了实处。\n"NOR,me,ob );
			return 0;
		}
		if( !me->query_temp("kongming/ming") 
		&& random(me->query_skill("kongming-quan",1)) < ob->query_skill("force",1)/2 ) {
			message_vision( HIW"$N潜运“空”字诀，化解了$n的大部分攻击。\n"NOR,me,ob );
			return -damage*3/4;
		}
		else if( !me->query_temp("kongming/ming")) {
			message_vision( HIW"$N潜运“空”字诀，将$n的大力化于无形。\n"NOR,me,ob );
			return -damage;
		}
		else {
			message_vision( HIW"$N潜运“空”字诀，但终因心分二用，无法凝神运气，结果只化解了$n的小部分攻击。\n"NOR,me,ob );
			return -damage/3;
		}
	}
	return -damage/4;
}

void kmq_must_be_hit(object me,object target,int i)
{
    if(!target) return;
    if(!me) {
        target->delete_temp("must_be_hit");
        if(living(target))
            message_vision(HIY"$n渐渐摸通了套路，松了一口气！\n"NOR,target);
        return;
    }

    if(me->query_skill_mapped("cuff")!="kongming-quan"
     ||me->query_skill_mapped("parry")!="kongming-quan"
     ||i<=0){
        if(living(target))
            message_vision(HIY"$n终于松了口气，开始反击！\n"NOR,me,target);
        target->delete_temp("must_be_hit");
        return;
    }
    call_out("kmq_must_be_hit",1,me,target,--i);
}
