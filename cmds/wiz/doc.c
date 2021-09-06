/*�����ж������������ݿ⹩��Ҳ�ѯ
ROOM
filename short long npc cmds code
NPC
filename name id skills inv room
 
*/

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object);   
void QueryNpcInfo(string path,int flag);
void QueryRoomInfo(string);
void QueryItemInfo(string);
string LoadNpc(object);
string QuerySkill(object);
string QueryObj(object);
string QueryAction(object,object);
string QueryEquipProp(object,mapping);

string status_color(int current, int max);
string conv(int i)
{
	if (i < 1000) return ""+i;
	return conv(i/1000)+sprintf(",%03d", i%1000);
}
int main(object me,string arg)
{
    
    string path,var;
    string *filename;

    if( !arg || sscanf(arg,"%s %s",path,var) != 2){
        return help(me);
    }
    if(file_size(path = resolve_path(me->query("cwd"),path)) != -2 )
        return notify_fail("û�����Ŀ¼��\n");
    seteuid(getuid());
    if(path[sizeof(path)-1] != '/')
        path += "/";
    switch(var)
    {
        case "-npc":
        case "-NPC":
            QueryNpcInfo(path,1);
            break;
        case "-room":
        case "-ROOM":
            QueryRoomInfo(path);
            break;
        case "-item":
        case "-ITEM":
            QueryItemInfo(path);
            break;
        default:
            write("�������ԣ����������룡\n");
            break;
    }
    return 1;
}
void QueryNpcInfo(string path,int flag)
{
    mapping my;
    string filename;
    string *file;
    object obj,me=this_player();
    int num=0;
    int lmt, i;
    if(flag){
    filename=path+"�ĵ�����֮NPCƪ";
    
    if(file_size(filename)>0)
        rm(filename);
    file=get_dir(path);

    foreach(string tmp in file){
        if (file_size(tmp) == -2)
            continue;
        write(sprintf("  ����%-15s����...",tmp));
        reset_eval_cost();
        obj=new(path + tmp);
        if (!objectp(obj) ){
            write(" ...ʧ�ܣ�\n");
            continue;
        }
        if(!obj->is_character() || !obj->query("name")){
            write("NOT NPC��\n");
            continue;
        }
        num ++;
    write_file(filename,"��������������������������������������������������������\n",0);
    write_file(filename,"�ļ���ţ�"+num+"\n",0);
    write_file(filename,"�ļ�λ�ã�"+base_name(obj)+".c\n",0);
    write_file(filename,"�ļ����ƣ�"+tmp+"\n",0);
    write_file(filename,"�������֣�"+obj->query("name")+"\n",0);
    write_file(filename,"Ӣ�ģɣ�: " + sprintf("%s",implode(obj->parse_command_id_list(), ","))+"\n",0);
    write_file(filename,QuerySkill(obj),0);
    write_file(filename,QueryObj(obj),0);
    write_file(filename,"��������������������������������������������������������\n");
	my = obj->query_entire_dbase();

	//if (userp(obj)){
		lmt = my["combat_exp"];
		for (i = to_int(pow(10.0 * lmt, 0.3333333));to_int(i*i/10.0*i)<=lmt;i++);
		my["max_pot"] = i+100;
	//}

	if (!my["max_jing"]) my["max_jing"] = 1;
	if (!my["max_qi"]) my["max_qi"] = 1;
	write_file(filename,sprintf("����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d%s(%d)\n" NOR,
		status_color(my["jing"], my["eff_jing"]+obj->query_temp("apply/jing")), my["jing"], my["eff_jing"]+obj->query_temp("apply/jing"),
		status_color(my["eff_jing"]+obj->query_temp("apply/jing"), my["max_jing"]), ((my["eff_jing"]+obj->query_temp("apply/jing")) * 100 / my["max_jing"]),
		status_color(my["jingli"], my["eff_jingli"]+obj->query_temp("apply/jingli")), my["jingli"], my["eff_jingli"]+obj->query_temp("apply/jingli"),
		status_color(my["jingli"], my["eff_jingli"]+obj->query_temp("apply/jingli")), my["eff_jingli"]-my["max_jingli"]+(obj->query_skill("force")-obj->query_temp("apply/force"))*8+obj->query_temp("apply/jingli")));
	write_file(filename,sprintf("����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d(+%d)\n" NOR,
		status_color(my["qi"], my["eff_qi"]+obj->query_temp("apply/qi")), my["qi"], my["eff_qi"]+obj->query_temp("apply/qi"),
		status_color(my["eff_qi"]+obj->query_temp("apply/qi"), my["max_qi"]), ((my["eff_qi"]+obj->query_temp("apply/qi")) * 100 / my["max_qi"]),
		status_color(my["neili"], my["max_neili"]+obj->query_temp("apply/neili")), my["neili"], my["max_neili"]+obj->query_temp("apply/neili"),
		my["jiali"] ));

	write_file(filename,sprintf("��%s����%s %-13s   " NOR " ���������ޡ�"HIC"%5d / %5d\n" NOR,
		my["shen"] < 0?"��":"��",
		my["shen"] < 0?HIR:HIC,
		conv((my["shen"] < 0?-1:1) * my["shen"]),
		(obj->query_skill("force")-obj->query_temp("apply/force"))*8 + my["combat_exp"]/1000 + obj->query_temp("apply/neili"),
		(obj->query_skill("force")-obj->query_temp("apply/force"))*10 + my["age"]*20 + my["combat_exp"]/1000 + obj->query_temp("apply/neili")));

	i = obj->max_food_capacity();
	if (!i) i = 1;
	write_file(filename,sprintf("��ʳ�%s%7.2f%%         " NOR "     ��Ǳ�ܡ�"HIY" %4d / %4d\n" NOR,
		status_color(my["food"], i),
		my["food"]*100.0/i, my["potential"], my["max_pot"] ));
	i = obj->max_water_capacity();
	if (!i) i = 1;
	write_file(filename,sprintf("����ˮ��%s%7.2f%%         " NOR "     �����顤"HIM" %s\n"NOR,
		status_color(my["water"], i),
		my["water"]*100.0/i,
		conv(obj->query("id") == "zhong shentong"?my["combat_exp"]/3*2:my["combat_exp"])));
        destruct(obj);
        write(" ...�ɹ��� \n");
    }
    write_file(filename,"��������������������������������������������������������\n",0);
    write_file(filename,"    ��Ŀ¼���ܹ���"+num+"��NPC�ļ���\n",0);
    write("��������������������������������������������������������\n");
    write("      ������"+chinese_number(num)+"����NPC�ļ�   \n\n");
       me->start_more(read_file(filename,1));
    }
    else{
    	obj=new(path);
        if (!objectp(obj) ){
            write(" ...ʧ�ܣ�\n");
            return;
        }
        if(!obj->is_character() || !obj->query("name")){
            write("NOT NPC��\n");
            return;
        }
        num ++;
    write_file(filename,"��������������������������������������������������������\n",0);
    write_file(filename,"�ļ���ţ�"+num+"\n",0);
    write_file(filename,"�ļ�λ�ã�"+base_name(obj)+".c\n",0);
    write_file(filename,"�ļ����ƣ�"+path+"\n",0);
    write_file(filename,"�������֣�"+obj->query("name")+"\n",0);
    write_file(filename,"Ӣ�ģɣ�: " + sprintf("%s",implode(obj->parse_command_id_list(), ","))+"\n",0);
    write_file(filename,QuerySkill(obj),0);
    write_file(filename,QueryObj(obj),0);
    write_file(filename,"��������������������������������������������������������\n");
	my = obj->query_entire_dbase();

	//if (userp(obj)){
		lmt = my["combat_exp"];
		for (i = to_int(pow(10.0 * lmt, 0.3333333));to_int(i*i/10.0*i)<=lmt;i++);
		my["max_pot"] = i+100;
	//}

	if (!my["max_jing"]) my["max_jing"] = 1;
	if (!my["max_qi"]) my["max_qi"] = 1;
	write_file(filename,sprintf("����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d%s(%d)\n" NOR,
		status_color(my["jing"], my["eff_jing"]+obj->query_temp("apply/jing")), my["jing"], my["eff_jing"]+obj->query_temp("apply/jing"),
		status_color(my["eff_jing"]+obj->query_temp("apply/jing"), my["max_jing"]), ((my["eff_jing"]+obj->query_temp("apply/jing")) * 100 / my["max_jing"]),
		status_color(my["jingli"], my["eff_jingli"]+obj->query_temp("apply/jingli")), my["jingli"], my["eff_jingli"]+obj->query_temp("apply/jingli"),
		status_color(my["jingli"], my["eff_jingli"]+obj->query_temp("apply/jingli")), my["eff_jingli"]-my["max_jingli"]+(obj->query_skill("force")-obj->query_temp("apply/force"))*8+obj->query_temp("apply/jingli")));
	write_file(filename,sprintf("����Ѫ��%s%5d / %5d %s(%3d%%)" NOR "  ��������%s%5d / %5d(+%d)\n" NOR,
		status_color(my["qi"], my["eff_qi"]+obj->query_temp("apply/qi")), my["qi"], my["eff_qi"]+obj->query_temp("apply/qi"),
		status_color(my["eff_qi"]+obj->query_temp("apply/qi"), my["max_qi"]), ((my["eff_qi"]+obj->query_temp("apply/qi")) * 100 / my["max_qi"]),
		status_color(my["neili"], my["max_neili"]+obj->query_temp("apply/neili")), my["neili"], my["max_neili"]+obj->query_temp("apply/neili"),
		my["jiali"] ));

	write_file(filename,sprintf("��%s����%s %-13s   " NOR " ���������ޡ�"HIC"%5d / %5d\n" NOR,
		my["shen"] < 0?"��":"��",
		my["shen"] < 0?HIR:HIC,
		conv((my["shen"] < 0?-1:1) * my["shen"]),
		(obj->query_skill("force")-obj->query_temp("apply/force"))*8 + my["combat_exp"]/1000 + obj->query_temp("apply/neili"),
		(obj->query_skill("force")-obj->query_temp("apply/force"))*10 + my["age"]*20 + my["combat_exp"]/1000 + obj->query_temp("apply/neili")));

	i = obj->max_food_capacity();
	if (!i) i = 1;
	write_file(filename,sprintf("��ʳ�%s%7.2f%%         " NOR "     ��Ǳ�ܡ�"HIY" %4d / %4d\n" NOR,
		status_color(my["food"], i),
		my["food"]*100.0/i, my["potential"], my["max_pot"] ));
	i = obj->max_water_capacity();
	if (!i) i = 1;
	write_file(filename,sprintf("����ˮ��%s%7.2f%%         " NOR "     �����顤"HIM" %s\n"NOR,
		status_color(my["water"], i),
		my["water"]*100.0/i,
		conv(obj->query("id") == "zhong shentong"?my["combat_exp"]/3*2:my["combat_exp"])));
        destruct(obj);
        write(" ...�ɹ��� \n");

    write_file(filename,"��������������������������������������������������������\n",0);
    write_file(filename,"    ��Ŀ¼���ܹ���"+num+"��NPC�ļ���\n",0);
    write("��������������������������������������������������������\n");
    write("      ������"+chinese_number(num)+"����NPC�ļ�   \n\n");
       me->start_more(read_file(filename,1));
    }
    
}
void QueryRoomInfo(string path)
{
    string filename;
    string *file;
    object obj;
    object finder=new("/clone/npc/trashcan");
       object me=this_player();
    int num=0;
    filename=path+"�ĵ�����֮ROOMƪ";
    
    if(file_size(filename)>0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(path+tmp) == -2)
            continue;
        write(sprintf("  ����%-15s����...",tmp));
        reset_eval_cost();
        obj=load_object(path+tmp);
        if (!objectp(obj) ){
            write(" ...ʧ�ܣ�\n");
            continue;
        }
        if( obj->is_character() || !stringp(obj->query("short")) ){
            write("NOT ROOM\n");
            continue;
        }
        num ++;
        write_file(filename,"��������������������������������������������������������\n",0);
        write_file(filename,"������ţ�"+num+"\n",0);
        write_file(filename,"�������ƣ�"+obj->query("short")+"\n",0);
        write_file(filename,"�ļ�λ�ã�"+base_name(obj)+".c\n",0);
        write_file(filename,"����������\n"+obj->query("long")+"\n",0);
        write_file(filename,LoadNpc(obj),0);
        write_file(filename,QueryAction(obj,finder),0);
        
        write(" ...�ɹ�\n");
    }
    write_file(filename,"��������������������������������������������������������\n",0);
    write_file(filename,"    ��Ŀ¼���ܹ���"+num+"�����䣡\n",0);
    write("��������������������������������������������������������\n");
    write("      ������"+chinese_number(num)+"���������ļ�   \n\n");
       me->start_more(read_file(filename,1));
    destruct(finder);
}
void QueryItemInfo(string path)
{
    string filename;
    string *file;
    object obj;
    //mapping prop;
       object me=this_player();    
    int num=0;
    //int flag=0;
    filename=path+"�ĵ�����֮ITEMƪ";
    
    if(file_size(filename)>0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(path+tmp) == -2)
            continue;
        write(sprintf("  ����%-15s����...",tmp));
        reset_eval_cost();
        obj=new(path + tmp);
        if (!objectp(obj) ){
            write(" ...ʧ�ܣ�\n");
            continue;
        }
        if( obj->is_character() || !stringp(obj->query("name")) ){
            write("NOT ITEM\n");
            continue;
        }
        num ++;
        write_file(filename,"��������������������������������������������������\n",0);
        write_file(filename,"��Ʒ��ţ�"+num+"\n",0);
        write_file(filename,"��Ʒ���ƣ�"+obj->query("name")+"("+
                    implode(obj->parse_command_id_list(),",")+")\n",0);
        write_file(filename,"��Ʒ�۸�"+MONEY_D->price_str((int)obj->query("value"))+"\n",0);
/*
        if(mapp(prop=obj->query("weapon_prop")))
            QueryEquipProp(obj,prop);
        else if(mapp(prop=obj->query("armor_prop")))
            QueryEquipProp(obj,prop);
*/
        destruct(obj);
        write(" ...�ɹ��� \n");
    }
    write_file(filename,"==================================================\n",0);
    write_file(filename,"    ��Ŀ¼���ܹ���"+num+"����Ʒ��\n",0);
    write("=========================================\n");
    write("      ������"+chinese_number(num)+"������Ʒ�ļ�   \n\n");
       me->start_more(read_file(filename,1));
}
string LoadNpc(object ob)
{

    string *p;
    mapping npc;
    string msg="",name;
    int i=0,count;
    object tmpnpc;

    if (stringp(ob->query("short")))
        name=ob->query("short");
    else name=ob->query("name");

    npc = ob->query("objects");
    count = sizeof(npc);
    if ( count == 0) 
    {
    return (name+"û���κ�NPC������Ʒ��\n");
    }
        
    p = sort_array(keys(npc), 1);

    msg += name +"����������NPC����Ʒ��\n";

    for (i=0; i < count; i++){
    	tmpnpc = new(p[i]);   	
    	msg += sprintf("%s%s\n",npc[p[i]]>1?(chinese_number(npc[p[i]])+"λ"):"",tmpnpc->short(1));
    }
    return msg;
}

string QueryAction(object ob,object finder)
{
    mixed *cmds;
    string msg="",name;
    int count=0;

    if (stringp(ob->query("short")))
        name=ob->query("short");
    else name=ob->query("name");

    finder->move(ob);
    cmds = finder->query_commands();
    if ( sizeof(cmds) == 1) return("");
    msg += name +"�ṩ����ָ�\n";
    foreach(mixed cmd in cmds){
        if( cmd[2]==finder ) continue;
        msg+=sprintf("%-10s   ", cmd[0]);
        count++;
        if(count%4==0)
            msg+="\n";
    }
    msg+="\n";
    return msg;
}
string QuerySkill(object ob)
{
    mapping m_skills,m_enable;
    string *sname;
    int i;    
    string msg="";

    m_skills = ob->query_skills();
    if ( !sizeof(m_skills) )
        return(ob->query("name")+"û��ѧ���κμ��ܡ�\n");
    msg += ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n";
    m_enable = ob->query_skill_map();
    if ( !mapp(m_enable) ) m_enable = ([]);
    sname=keys(m_skills);
    msg=msg+"��������������������������������������������������������\n";
    for ( i = 0; i < sizeof( m_skills ); i++ ){
        msg=msg+sprintf( "%s%-12s%-28s%8d\n",
            m_enable[ sname[i] ] ? "��" : "  ",
            to_chinese(sname[i]),  "(" + sname[i] + ")",
            m_skills[sname[i]]);        
        }
    return msg;
}
string QueryObj(object ob)
{
    	object *inv;
	string *key, unit;
	mixed first;
	int i;
	string msg = "��������������������������������������������������������\n";
	
    	inv = filter_array(all_inventory(ob), "visible", ob);
	if (!sizeof(inv)) {
		msg +=  ob->name() + "����û��Я���κζ�����\n";
		return msg;
	}

	msg += sprintf("%s���ϴ���%s������(���� %:2f%%)��\n",
		ob->name(),
		chinese_number(sizeof(inv)),
		ob->query_encumbrance() * 100.0 / ob->query_max_encumbrance()
	);

	first = filter_array(inv,
		(: $1->query("base_unit") && !$1->query("equipped") && !$1->query("embedded") :)
	);
	first += filter_array(inv,
		(: $1->query("equipped") :)
	);
	first += filter_array(inv,
		(: $1->query("embedded") :)
	);

	foreach(object item in first) {
		unit = sprintf("%s",
			(item->query("equipped")? HIC"��"NOR :item->query("embedded")? HIR"��"NOR: "  ")+
			item->short()
		);

		msg += unit + "\n";
	}

	inv -= first;
	i = sizeof(inv);


	first = ([]);
	foreach(object item in inv) {
		unit = base_name(item) + item->name();
		if( !mapp(first[unit]) ) {
			first[unit] = ([
				"total" : 1,
				"unit" : item->query("unit"),
				"short" : item->short(),
			]);
			//if ( wiz ) first[unit]["weight"] = item->weight();
		} else first[unit]["total"]++;
	}

	key = keys(first);

	foreach(string item in key) {
		unit = sprintf("  %s", chinese_number(first[item]["total"]) + first[item]["unit"] + first[item]["short"]);
		msg += unit + "\n";
	}
	//write(str);
	//if ( wiz ) write("��������" + ob->query_encumbrance() + "\n");
    return msg;
}

string QueryEquipProp(object equip,mixed props)
{
    string type,msg="";
    int i;
    //int count=0;
    string *prop;

    if(stringp(type=equip->query("skill_type")))
        msg+=sprintf("�������ͣ�%-10s     �� �� ����%d",type,(int)equip->query("weapon_porp/damage"));
    else if(stringp(type=equip->query("skill_type")))
        msg+=sprintf("�������ͣ�%-10s     �� �� ����%d",type,(int)equip->query("armor_porp/armor"));
    if ( !sizeof(props)) return("");
    msg += "          "+equip->name()+"��������Ч��\n";
    prop=keys(props);
    for (i=0;i<sizeof(props);i++){
// foreach(string prop in props){
        if( prop[i]=="armor"||prop[i]=="damage")
            continue;
        msg+=sprintf("%-12d  ", props[prop[i]]);
        if(i%4==0)
            msg+="\n";
    }
    return msg;
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
int help(object me)
{
    write(@HELP
ָ���ʽ��doc ·���� -������ 
Ŀǰ�ṩ�������У�room��npc��item
����
    doc /d/city/npc -npc
���������ʱ��ò�ʹ�ô�ָ�
HELP);
    return 1;
}