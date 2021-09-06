/*
����������ĸ���״̬�������������������������������������������Щ�����������������������
������Ѫ�� 4734/  4734 (100%)   ��������5956 /  5956(5956)    ���ֳ֣�������          ��
������Ѫ��10372/ 10372 (100%)   ��������17570/ 17570 (+100)   ��������ɫʥ��        ��
���������� 0                ���������ޡ�15576 / 17610         ���Ŵ�������            ��
����ʳ�   60/   150          ��Ǳ�ܡ�  565 /  565          ���ִ�����              ��
������ˮ��   71/  150           �����顤 10,000,011 (15.88%)  ���ִ�����              ��
���������������������������������������������������������������ة�����������������������
�ٺ�
*/

#include <ansi.h>
void refresh_show(object me,int i,int j,string str);
void refresh_show_head(object me,string str);
string status_color(int current, int max);
void refresh_clear(object me,int x,int y,int k);
void refresh_screen_all(object me);

void refresh_kuangjia(object me);
void refresh_head(object me);
void refresh_jing(object ob);void refresh_jingli(object ob);void refresh_weapon(object me);
void refresh_qi(object me);void refresh_neili(object me);void refresh_cloth(object me);
void refresh_shen(object me);void refresh_maxneili(object me);void refresh_boots(object me);
void refresh_food(object me);void refresh_pot(object me);void refresh_armor(object me);
void refresh_water(object me);void refresh_exp(object me);void refresh_surcoat(object me);
void refresh_tail(object me);


void refresh_clear(object me,int x,int y,int k)
{	
	string kg = "";
	while(k--)
		kg += " ";
	refresh_show(me,x,y,kg);	
}

string conv(int i)
{
	if (i < 1000) return ""+i;
	return conv(i/1000)+sprintf(",%03d", i%1000);
}

void refresh_show(object me,int x,int y,string str)
{
	tell_object(me,SAVEC);
	tell_object(me,SET(x,y));
	tell_object(me,str);
	tell_object(me,REST);
}

void refresh_show_head(object me,string str)
{
	tell_object(me,str);
}

void show_two_screen(object ob)
{
	refresh_kuangjia(ob);
	refresh_screen_all(ob);
	refresh_show_head(ob,SET(8,0));	
	ob->set_temp("show_frozen",1);
}
void refresh_clear_all(object ob)
{
	int i = 8;
	while(i--) refresh_clear(ob,i,0,88);
	refresh_show_head(ob,FR(0));
	refresh_show_head(ob,CLR);
	ob->delete_temp("show_frozen");
}
void refresh_screen_all(object me)
{
	refresh_jing(me);
	refresh_jingli(me);
	refresh_weapon(me);
	refresh_qi(me);
	refresh_neili(me);
	refresh_cloth(me);
	refresh_shen(me);
	refresh_maxneili(me);
	refresh_boots(me);
	refresh_food(me);
	refresh_pot(me);
	refresh_armor(me);
	refresh_water(me);
	refresh_exp(me);
	refresh_surcoat(me);	
}
string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 0;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

////��Ʒ
void refresh_surcoat(object me)
{
	string name;
	refresh_clear(me,6,71,16);	
	if (me->query_temp("armor/surcoat")) name = me->query_temp("armor/surcoat")->query("name");
	else name=HIW"��"NOR;	
	refresh_show(me,6,71,name);	
}
void refresh_armor(object me)
{	
	string name;
	refresh_clear(me,5,71,16);	
	if (me->query_temp("armor/armor")) name = me->query_temp("armor/armor")->query("name");
	else name=HIW"��"NOR;	
	refresh_show(me,5,71,name);	
}

void refresh_boots(object me)
{
	string name;
	refresh_clear(me,4,71,16);	
	if (me->query_temp("armor/boots")) name = me->query_temp("armor/boots")->query("name");
	else name=HIW"��"NOR;	
	refresh_show(me,4,71,name);	
}
void refresh_cloth(object me)
{
	string name;
	refresh_clear(me,3,71,16);	
	if (me->query_temp("armor/cloth")) name = me->query_temp("armor/cloth")->query("name");
	else name=HIW"��"NOR;	
	refresh_show(me,3,71,name);	
}
void refresh_weapon(object me)
{
	string name;
	refresh_clear(me,2,71,16);	
	if (me->query_temp("weapon")) name = me->query_temp("weapon")->query("name");
	else name=HIW"�ޱ���"NOR;	
	refresh_show(me,2,71,name);	
}

void refresh_jingli(object ob)
{
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,2,41,22);	
	refresh_show(ob,2,41,sprintf("%s%5d / %5d%s(%d)\n" NOR,
		status_color(my["jingli"], my["eff_jingli"]+ob->query_temp("apply/jingli")), 
		my["jingli"], 
		my["eff_jingli"]+ob->query_temp("apply/jingli"),
		status_color(my["jingli"], 
		my["eff_jingli"]+ob->query_temp("apply/jingli")), 
		my["eff_jingli"]-my["max_jingli"]+(ob->query_skill("force")-ob->query_temp("apply/force"))*8+ob->query_temp("apply/jingli")
		));        
}

void refresh_food(object ob)
{
	int i;
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,5,11,22);
        i = ob->max_food_capacity();
	if (!i) i = 1;
	
	refresh_show(ob,5,11,sprintf("%s%7.2f%%	 " NOR,
		status_color(my["food"], i),
		my["food"]*100.0/i,
		));
}

void refresh_pot(object ob)
{
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,5,41,22);	
	refresh_show(ob,5,41,sprintf(HIY" %4d / %4d\n" NOR,
		my["potential"], my["max_pot"] ));	
}

void refresh_maxneili(object ob)
{
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,4,41,22);	
	refresh_show(ob,4,41,sprintf(HIC"%5d / %5d\n" NOR,		
		(ob->query_skill("force")-ob->query_temp("apply/force"))*8 + my["combat_exp"]/1000 + ob->query_temp("apply/neili"),
		(ob->query_skill("force")-ob->query_temp("apply/force"))*10 + my["age"]*20 + my["combat_exp"]/1000 + ob->query_temp("apply/neili")));	
}

void refresh_shen(object ob)
{
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,4,0,28);	
	refresh_show(ob,4,0,sprintf("����%s����%s %-13s"NOR,
		my["shen"] < 0?"��":"��",
		my["shen"] < 0?HIR:HIC,
		conv( (my["shen"] < 0?-1:1)*my["shen"]),
		));	
}
void refresh_neili(object ob)
{
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,3,41,22);	
	refresh_show(ob,3,41,sprintf("%s%5d / %5d(+%d)\n" NOR,
		status_color(my["neili"], my["max_neili"]+ob->query_temp("apply/neili")), 
		my["neili"], 
		my["max_neili"]+ob->query_temp("apply/neili"),
		my["jiali"] ));        
}
void refresh_exp(object ob)
{
	mapping my = ob->query_entire_dbase();
	int i,lmt;
	
	if (userp(ob)){
		lmt = my["combat_exp"];
		for (i = to_int(pow(10.0 * lmt, 0.3333333));to_int(i*i/10.0*i)<=lmt;i++);
		lmt = i;
		my["max_pot"] = i+100;
	}	
	refresh_clear(ob,6,41,22);	
	refresh_show(ob,6,41,sprintf(HIM" %s (%.2f%%)\n"NOR,
		conv(ob->query("id") == "zhong shentong"?my["combat_exp"]/3*2:my["combat_exp"]),
		lmt > 0 ? (my["combat_exp"] - to_int((lmt-1)*(lmt-1)/10.0*(lmt-1)))*100.0/(to_int(lmt*lmt/10.0*lmt) - to_int((lmt-1)*(lmt-1)/10.0*(lmt-1))) : 100.0));        
}


void refresh_water(object ob)
{	
	int i;
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,6,11,22);	
	i = ob->max_water_capacity();
	if (!i) i = 1;	
	refresh_show(ob,6,11,sprintf("%s%7.2f%%"NOR,
		status_color(my["water"], i),
		my["water"]*100.0/i,
		));        
}

void refresh_jing(object ob)
{	
	mapping my = ob->query_entire_dbase();	
	refresh_clear(ob,2,11,22);	
	refresh_show(ob,2,11,sprintf("%s%5d / %5d %s(%3d%%)"NOR,
		status_color(my["jing"], my["eff_jing"]+ob->query_temp("apply/jing")), 
		my["jing"], 
		my["eff_jing"]+ob->query_temp("apply/jing"),
		status_color(my["eff_jing"]+ob->query_temp("apply/jing"), 
		my["max_jing"]), 
		((my["eff_jing"]+ob->query_temp("apply/jing")) * 100 / my["max_jing"]),
		));        
}

void refresh_qi(object ob)
{
	mapping my = ob->query_entire_dbase();
	refresh_clear(ob,3,11,22);	
	refresh_show(ob,3,11,sprintf("%s%5d / %5d %s(%3d%%)"NOR,
		status_color(my["qi"], my["eff_qi"]+ob->query_temp("apply/qi")), 
		my["qi"], 
		my["eff_qi"]+ob->query_temp("apply/qi"),
		status_color(my["eff_qi"]+ob->query_temp("apply/qi"), my["max_qi"]),
		((my["eff_qi"]+ob->query_temp("apply/qi")) * 100 / my["max_qi"]),
		));        
}

void refresh_kuangjia(object me)
{
	int i;
	refresh_show_head(me,CLR);
	refresh_show_head(me,FR(8));	
	for (i=2;i<=6;i++){
		refresh_show(me,i,63,"��");
		refresh_show(me,i,87,"��");	 	
	}
	refresh_head(me);
	refresh_tail(me);	
	refresh_show(me,2,0,"������Ѫ��");	
	refresh_show(me,2,33,"��������");	
	refresh_show(me,2,65,HIY"�ֳ֣�"NOR);	
	refresh_show(me,3,0,"������Ѫ��");	
	refresh_show(me,3,33,"��������");	
	refresh_show(me,3,65,HIY"����"NOR);	
	refresh_show(me,4,29,"���������ޡ�");	
	refresh_show(me,4,65,HIY"���ţ�"NOR);
	refresh_show(me,5,0,"����ʳ�");
	refresh_show(me,5,33,"��Ǳ�ܡ�");	
	refresh_show(me,5,65,HIY"�����"NOR);	
	refresh_show(me,6,0,"������ˮ��");	
	refresh_show(me,6,33,"�����顤");	
	refresh_show(me,6,65,HIY"������"NOR);	
}
void refresh_head(object me)
{	
        refresh_show(me,1,0,"����"HIG"��ĸ���״̬"NOR"�����������������������������������������������Щ�����������������������");	
}
void refresh_tail(object me)
{	
        refresh_show(me,7,0,"���������������������������������������������������������������ة�����������������������");	
}
