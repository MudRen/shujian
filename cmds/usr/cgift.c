// YUJ@SJ 2001-11-02
// Modified by LOOKLOVE@SJ 引入乘幂计算，大大优化。
// 2002/4/29
// 改为玩家自行修改属性

// Exp在 100K 以上可以修改属性。
#define MIN_EXP 150000
// 剩余EXP比率等于100%减去每点扣除比率
// 当前修改每点属性，扣除exp比率为1%
#define RATE 1

inherit F_CLEAN_UP;
#include <ansi.h>

int help();

nosave mapping gift_desc = ([
	"str":"膂力",
	"con":"根骨",
	"dex":"身法",
	"int":"悟性"
]);

nosave string *gift = keys(gift_desc);

string check(object me)
{
	string msg;

	if (me->query("registered") < 3)
		msg = HIY"系统提示："NOR"抱歉，只有贵宾才有这个机会。\n";
	if (me->is_ghost())
		msg = HIY"系统提示："NOR"抱歉，你的状态不稳定，现在无法修改属性。\n";
	return msg;
}

int check_exp(int exp, int num)
{
        if(exp <= 5200000) return exp;
        else while (num--) exp -= exp / 100;
        return exp;
}

int vipcheck_exp(int exp, int num)
{
        if(exp <= 25000000) return exp;
        else while (num--) exp -= exp* 9 / 1000;
        return exp;
}

int main(object me, string arg)
{
	string msg, from, to;
	int exp, num, newexp, tmpexp;

	if (!me) return 0;
	if (!arg) return help();

	if ( stringp(msg = check(me)) )
		return notify_fail(msg);

	exp = me->query("combat_exp");

	if (sscanf(arg, "%d %s to %s", num, from, to) == 3){		
		if (member_array(from, gift) < 0)
			return notify_fail("你要扣除什么天赋？\n");
		if (member_array(to, gift) < 0)
			return notify_fail("你要增加什么天赋？\n");
		if (from == to || num<0 )
			return notify_fail("检查一下，输入错误，可能眼花。\n");
//                if(exp<1000000 && from=="int")
//                        return notify_fail("你的经验值小于1M，不能将悟性减少。\n");
		if (me->query(from) <= 10)
			return notify_fail("你的"+gift_desc[from]+"不能再减少了。\n");
		if ( ((int)me->query(from) - num) < 10)
			return notify_fail("你的"+gift_desc[from]+"减少"+num+"点后将少于10点，不能修改。\n");
                if (me->query(to) >= 32 )
                        return notify_fail("你的"+gift_desc[to]+"已经到达极限了，不能再增加了。\n");
                if ( ((int)me->query(to) + num) > 32 )
                        return notify_fail("你的"+gift_desc[to]+"增加"+num+"点后将超过32点，不能修改。\n");

		switch (me->query("family/family_name")) {
			case "明教":
				if (from == "int" && ( me->query("int") <= 20 || ((int)me->query("int") - num) <20 ) )
					return notify_fail("明教弟子悟性要求至少 20。\n");
				break;
			case "大轮寺":
				if (from == "str" && ( me->query("str") <= 20 || ((int)me->query("str") - num) <20) )
					return notify_fail("大轮寺弟子膂力要求至少 20。\n");
				if (from == "con" && ( me->query("con") <= 20 || ((int)me->query("con") - num) <20) )
					return notify_fail("大轮寺弟子根骨要求至少 20。\n");
				break;
		}

		input_to("confirm_passwd", me, from, to, num);
		write("确认修改属性成功！\n");
		return 1;
	}

	if (sscanf(arg, "check %d", num) == 1){

                if ( num > 200 )
			return notify_fail("输入的数值超过了你的隐藏属性合。\n");
	// 计算扣除exp
		newexp = check_exp(exp,num);
if(me->query("buyvip")) newexp = vipcheck_exp(exp,num);
		tmpexp = exp - newexp;

		msg = HIG"提示：如果要修改 "+num+" 点属性，你大约要扣除 "+tmpexp+" 点EXP，还剩 "+newexp+" 点EXP。\n"NOR;
if(me->query("can_cgift")) 
                                msg += HBRED"恭喜！因为你使用了洗髓丹，所以你可以自由调整一次天赋而无需损耗任何经验。\n"NOR;
		if ( newexp < 150000 )
			msg += HIR"抱歉：修改"+num+"点属性后经验将不够 "+MIN_EXP+" ，建议你一次少修改几点属性。\n"NOR;
		if (me->query_skill("jinshe-zhangfa",1) || me->query_skill("jinshe-jianfa",1))
                        msg += HIR"注意：如果修改臂力高于20且少于30，金蛇剑法和金蛇掌法将被删除。\n"NOR;

		if (me->query("double_attack") && me->query("zhou"))
                        msg += HIR"注意：如果修改悟性高于25且少于31，左右互搏将被删除。\n"NOR;

		if (me->query("dali") && me->query_skill("lingbo-weibu", 1))
			msg += HIR"注意：如果修改悟性低于22，凌波微步将被删除。\n"NOR;

		write(msg);
		return 1;
	}
	return help();
}

private void confirm_passwd(string pass, object me, string from, string to, int num)
{
	int exp, newexp, tmpexp;

	// 计算扣除exp

	exp = me->query("combat_exp", 1);
//        if( me->query("combat_exp") > 52000000 && !me->query("can_cgift") ) {
        if( me->query("combat_exp") > 5200000 && !me->query("can_cgift") ) {
	     newexp = check_exp(exp,num);
if( me->query("buyvip")) newexp = vipcheck_exp(exp,num);
	     tmpexp = exp - newexp;
	     me->add(from, -num);
	     me->add(to, num);
	     me->add("combat_exp", -tmpexp);
     }
   else
      {
            tmpexp = 0;
            me->add(from, -num);
	     me->add(to, num);
	     me->add("combat_exp", -0);
      	}
		
	me->start_busy(1);

	

	write("你将"+num+"点"+gift_desc[from]+"调整到"+gift_desc[to]+"上。\n", me);
	write("扣除 "+tmpexp+" 点经验\n", me);
        
	me->save();
     if(me->query("can_cgift")) {
          me->delete("can_cgift"); 	
	write(HIM"你感觉洗髓丹发挥了特殊的效力，你本次的天赋调整没有损耗任何经验。\n"NOR, me);
	write(HIR"你服用的洗髓丹的效力已经渐渐散去了。\n"NOR, me);
                                   }

log_file("static/ADJUST",
		me->query("name")+"("+capitalize(geteuid(me))+")"
		+"调整"+num+"点"+gift_desc[from]
		+"到"+gift_desc[to]+"上，扣除 "+tmpexp+" 点经验，剩余"+newexp+"\n",
		me,
		({ me })
	);
	return;
}

int help()
{
	write("本指令用来修改先天属性。\n");
       write("实战经验5.2M以后每点属性修改将扣除1% exp。\n");
       write("荣誉贵宾放宽为25M且每点属性修改只扣除0.9% exp。\n");
       write("你也可以用洗髓丹来自由调整一次天赋。\n");
	write("EXP不足"+MIN_EXP+"不能修改属性。\n");
	write("指令格式：\n");
	write("计算扣除损失：cgift check <要修改的点数>\n");
	write("修改属性：cgift <点数> <要扣除的天赋> to <要增加的天赋>\n");
	write("比如：你要把一点膂力加到悟性上，你可以用："HIG" cgift 1 str to int "NOR"\n");
	write("四项先天属性代号如下:膂力:str,根骨:con,身法:dex,悟性:int\n");
	write("请慎重使用。\n");
//        write("\n特别注意：经验值小于1M不能减少悟性。\n");

	return 1;
}
