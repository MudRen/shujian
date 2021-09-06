// ɨ����Ϸ
/*
	by snowman@SJ 20/11/2000
	
	Copyright 1997-1999 ShuJian MUD Wizard Group.
   	All rights reserved.
*/

// fixed some little bugs.. snowman@SJ

#include <ansi.h>
#define CLR ESC+"[2J"

inherit ROOM;
inherit F_SAVE;

nosave int x = 15, y = 20, bomb = 40;
nosave string *number = ({ "��",CYN"��"NOR,HIG"��"NOR,HIR"��"NOR,HIC"��"NOR,RED"��"NOR,HIM"��"NOR,MAG"��"NOR,BLU"��"NOR,WHT"��"NOR,"��",HIY"��"NOR });
nosave mapping game;
nosave mapping map;
nosave int mine = 0, real_mine = 0, t = 0;
nosave string player, table = "��������ʲôҲû�С�\n";
nosave string rules = "      
       	
��ɨ�ס���Ϸ��Ŀ����Ѹ���ҵ������е����е��ף�������ȵ����ס�
Ҫ�ҿ�ĳ�����飬��ʹ��"CYN" mine dig x?y? "NOR"�������������ҷ��������ף�����������һ�֡� 
��������ϳ������֣�������������Χ�İ˸������й��ж��ٿŵ��ס� 
�������Ϊĳ�����������ŵ��ף�����"CYN" mine at x?y?"NOR" ȷ�������������е��׾�Ӯ�� 

Ŀǰ��ʡȴֵ�� "+bomb+" ö���ף� X��Ϊ"+x+"��Y��Ϊ"+y+"��
ϵͳ�Զ���¼���ʱ��ǰʮ������Ҽ�����ʱ��(list)��

��Ϸָ�
	"HIC"mine start"NOR"	��	��ʼ��Ϸ��
	"HIC"mine cancel"NOR"	��	����Ŀǰ����Ϸ��
	"HIC"mine dig x?y?"NOR"	��	��λ�ڵ� ? ��X��͵� ? ��Y��ķ��顣
	"HIC"mine at x?y?"NOR"	��	ȷ��λ�ڵ� ? ��X��͵� ? ��Y��ķ����ǵ��ס�
	"HIC"mine re x?y?"NOR"	��	ȡ���˷���ĵ���ȷ����
	"HIC"mine finish"NOR"	��	�����ȷ�����Ѿ��ҳ������е��ף���������
	
����Ϸ���� Microsoft (R) ɨ��

\n";

mapping *top10;
string look_map();
string look_table();
void clean_table();

void create()
{
	seteuid(getuid());
	restore();
	delete("no_death");
	if (!sizeof(top10)) top10 = ({ ([ "id": "beginner", "time": 3600 ]) });
	
        set("short", YEL"ɨ����Ϸ��"NOR);
        set("long", @LONG
�������齣���ɨ����أ�������ɨ��(Minesweep����Ϸ��ۿ������е�
����������Ϸ�����(table)���Աߵ�����(paizi)��д����Ϸ������淨��һ
���ǳɼ���(list)��
LONG    );

        set("no_fight", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1); 
        set("item_desc", ([             
        	"list" : (: look_map :),  
        	"table" : (: look_table :),        
             	"paizi" : rules,
        ]));
        set("exits", ([
        	"south" : __DIR__"chmiao",
           	//"up" : SP_A("wizard/guest_room"),
        ]));

        set("incity",1);
	setup(); 
}

void init()
{
	object me = this_player();
	if (!userp(me)) return;
	add_action("do_set", "mineset");
	add_action("main_mine", "mine");	                          
}

string look_table(){ return table; }
       
string look_map()
{
	int i;
	string tmp = HIW"��ѳɼ���\n"NOR;
	for (i = 0; i < sizeof(top10); i++){
		if( i > 9 ){
			top10[i] = 0;
			continue;
		}
		tmp += sprintf(" %-2s��%-8s "HIY"��"NOR" %s\n", (i+1)+"", capitalize(top10[i]["id"]), CHINESE_D->chinese_time(top10[i]["time"]));
	}
	top10 -= ({ 0 });
	return tmp;
}         
     
int do_set(string arg)
{
	int i, j, k;
	if( !wizardp(this_player()) )
		return notify_fail("ָ�mine <dig|at|re x?y?> | start | cancel | ? ��\n");
	if( sscanf(arg, "%d x%d y%d", k, i, j) == 3 ){
		if( k < 10 || i < 10 || j < 10 )
			return notify_fail("set <bomb> x<��Ŀ> y<��Ŀ>�� ����������Ϊ 10��\n");
		if( k > 99 )
			return notify_fail("set <bomb> x<��Ŀ> y<��Ŀ>�� ���������Ϊ 99��\n");
		if( i > 25 || j > 35 )
			return notify_fail("set <bomb> x<��Ŀ> y<��Ŀ>�� x���Ϊ 25��y���Ϊ 35��\n");
		bomb = k;
		x = i;
		y = j;
		clean_table();
		return notify_fail("��������"+ bomb +"��X �᣺"+ x +"��Y �᣺"+ y +"��\n");
	}
	else return notify_fail("��ʽ��mineset <bomb> x<��Ŀ> y<��Ŀ>��\n");
}


int remove()
{
	save();
	return 1;
}

string query_save_file()
{
	return "/log/mine_rank";
}

int clean_all()
{
	top10 = ({ ([ "id": "beginner", "time": 3600 ]) });
	return remove();
}

void clean_table()
{
	int i;
	game = mine = real_mine = t = 0;
	player = 0;
	table = "��������ʲôҲû�С�\n";
	map = allocate_mapping(x);
	for(i = 0; i < x; i++ ){
		map[i] = allocate_mapping(y);
	}
	tell_room(this_object(), HIW"\n��Ϸ�������¿�ʼ�ˣ�\n"NOR);	
}
mapping make_game(int mines)
{
	mapping m = allocate_mapping(x);
	int k, i, j;
	
	for(i = 0; i < x; i++ ){
		m[i] = allocate_mapping(y);
	}

	i = x;
	j = y;
	for(k = 0;k < mines; k++){
		i = random(x);
		j = random(y);
		if( m[i][j] == 9 ){
			k--;
			continue;
		}
		else	m[i][j] = 9;
	}
	
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			k = m[i][j];
			if( k != 9 ){
				if( j > 0 && m[i][j-1] == 9 ) k++;
				if( j < y-1 && m[i][j+1] == 9 ) k++;
				if( i > 0 && m[i-1][j] == 9 ) k++;
				if( i < x-1 && m[i+1][j] == 9 ) k++;
				if( i-1 >= 0 ){
					if( j-1 >= 0 && m[i-1][j-1] == 9 ) k++;
					if( j+1 < y && m[i-1][j+1] == 9 ) k++;
				}
				if( i+1 < x ){
					if( j-1 >= 0 && m[i+1][j-1] == 9 ) k++;
					if( j+1 < y && m[i+1][j+1] == 9 ) k++;
				}
			}
			m[i][j] = k;
		}
	}
	return m;
}
string drew_map(int k)
{
	int i, j;
	string str = YEL"������ "+ player +" ��ɨ�ס�\n\n   "NOR;
	
	for(i = 0; i < y; i++)
		str += sprintf("%-2s", (i+1)+"");
	str += " ��Y��\n 1,";
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			if( k )
				str += number[game[i][j]];
			else 	str += number[map[i][j]];
		}
		if( i < x-1 )
			str += "\n"+sprintf("%3s", (i+2)+",");
		else str += "\n��\t����������"+ bomb +"��Ŀǰ��̽������"+ mine +"��\nX��\n";
	}
	table = str;
	return str;
}

int block_check(int i, int j)
{
	int k, l = 0;
	if( i-1 >= 0 ){
		if( (k = game[i-1][j]) < 9 && map[i-1][j] < 9 ) map[i-1][j] = ((k == 0)?10:k);
		else l += 1;
	}
	if( i+1 < x ){
		if( (k = game[i+1][j]) < 9 && map[i+1][j] < 9 ) map[i+1][j] = ((k == 0)?10:k);
		else l += 2;
	}
	if( (j-1) >= 0 ){
		if( (k = game[i][j-1]) < 9 ){
			if( map[i][j-1] < 9 )
		 		map[i][j-1] = ((k == 0)?10:k);
		}
		else l += 3;
		if( i-1 >= 0 )
			if( (k = game[i-1][j-1]) < 9 && map[i-1][j-1] < 9 && l % 4 != 0 ) map[i-1][j-1] = ((k == 0)?10:k);
		if( i+1 < x )
			if( (k = game[i+1][j-1]) < 9 && map[i+1][j-1] < 9 && l % 5 != 0 ) map[i+1][j-1] = ((k == 0)?10:k);
	}
	if( (j+1) < y ){
		if( (k = game[i][j+1]) < 9 ){ 
			if( map[i][j+1] < 9 )
				map[i][j+1] = ((k == 0)?10:k);
		}
		else l += 5;
		if( i-1 >= 0 )
			if( (k = game[i-1][j+1]) < 9 && map[i-1][j+1] < 9 && l % 6 != 0 ) map[i-1][j+1] = ((k == 0)?10:k);
		if( i+1 < x )
			if( (k = game[i+1][j+1]) < 9 && map[i+1][j+1] < 9 && l % 7 != 0 ) map[i+1][j+1] = ((k == 0)?10:k);
	}
}
int main_mine(string arg)
{
	int i, j, k;
	object ob, me;
	string tmp = YEL"\nɨ����Ϸ��"NOR;
	
	if( !arg ){
		if( game )
			 return notify_fail(table);
		else return notify_fail("ָ�mine <dig|at|re x?y?> | start | cancel | finish ��\n");
	}
	me = this_player();
	if( !player ) player = me->query("id");
	
	else if( player != me->query("id") ){
		ob = LOGIN_D->find_body(player);
		if( objectp(ob) && environment(ob) == this_object() && ob->query_idle(ob) < 180 ) 
			return notify_fail("��������"+ob->name()+"�����أ����ȵȵȡ�\n");
		else {
			clean_table();
			player = me->query("id");
		}
	}	
	
	// mine cancel
	if( arg == "cancel" ){
		clean_table();
		tmp += "����Ϸ�Ѿ�����ɾ���\n";	
	}
	else if( arg == "start" ){
		if( game )
			return notify_fail("��Ϸ�Ѿ���ʼ�ˣ��� mine <dig|at|re x?y?> ��Ϸ�� mine cancel ����\n");
		clean_table();
		player = me->query("id");
		game = make_game(bomb);
		t = time();
		if( wizardp(me) && me->query("env/mine") )
			tmp += drew_map(1);
		else 	tmp += drew_map(0);
	}
	
	// mine finish
	else if( arg == "finish" ){
		if( !game )
			return notify_fail("��Ϸ��û��ʼ�أ��� mine start ��ʼ��\n");
		if( mine < bomb || real_mine < bomb || real_mine < mine )
			return notify_fail("�㻹û����ȫ̽�����أ������ɣ�\n");
		tmp += drew_map(0);
		tmp += "̽������ȷ����"+ real_mine +"��";
		t = time() - t;
		tmp += player+"�ɹ��������������񣡣��ܹ�ʹ����"+ CHINESE_D->chinese_time(t) +"��\n";
		k = sizeof(top10);
		for (i = 0; i < k; i++){
			if( i > 9 ) break;
			if( t < top10[i]["time"] ){
				top10 = top10[0..i-1] + ({ ([ "id": me->query("id"), "time":t, ]) }) + top10[i..k];
				me->add("balance", (10-i) * 500000 );  // base reward is 50 gold.
				tmp += "\n�˴γɼ�ΪĿǰ������" + chinese_number(i+1) + "��������"+MONEY_D->money_str((10-i) * 500000)+"��\n";
				break;
			}
		}
		clean_table();
	}
	
	// mine dig xxxx
	else if( sscanf(arg, "dig x%dy%d", i, j) == 2 ){
		if( !game )
			return notify_fail("��Ϸ��û��ʼ�أ��� mine start ��ʼ��\n");
		if( i > x || i < 1 ) 
			return notify_fail("Xֵ̫���̫С�ˡ�\n");
		if( j > y || j < 1 ) 
			return notify_fail("Yֵ̫���̫С�ˡ�\n");
		tmp += "ѡ���� X"+i+"��Y"+j+" �ĵط��ھ�\n";
		i--;
		j--;
		if( i < 0 ) i = 0;
		if( j < 0 ) j = 0;
		if( map[i][j] > 10 ) 
			return notify_fail("�˵ز��ɵ㣬��������ȡ����־��\n");
		k = game[i][j];
		if( k < 9 ){
			block_check(i, j);
			if( k == 0 )
				k = 10;
		}
		map[i][j] = k;
		tmp += drew_map(0);
		if( map[i][j] == 9 ){
			t = time() - t;
			tmp += HIR"������"+ CHINESE_D->chinese_time(t) +"������˵��ף���Ϸ������\n"NOR;
			tmp += "ɨ�׵���ȷ����"+ real_mine +"��\n";
			clean_table();
		}
	}
	
	// mine at xxxx
	else if( sscanf(arg, "at x%dy%d", i, j) == 2 ){
		if( !game )
			return notify_fail("��Ϸ��û��ʼ�أ��� mine start ��ʼ��\n");
		if( i > x || i < 1 ) 
			return notify_fail("Xֵ̫���̫С�ˡ�\n");
		if( j > y || j < 1 ) 
			return notify_fail("Yֵ̫���̫С�ˡ�\n");
		tmp += "ѡ���� X"+i+"��Y"+j+" �ĵط�����־��\n";
		i--;
		j--;
		if( i < 0 ) i = 0;
		if( j < 0 ) j = 0;
		if( map[i][j] == 11 )
			return notify_fail("�˵��Ѿ�̽�������ñ�־�ˣ�Ҫȡ������ mine re x?y?��\n");
		map[i][j] = 11;
		mine++;
		if( game[i][j] == 9 )
			real_mine++;
		tmp += drew_map(0);
	}
	
	// mine re xxxx
	else if( sscanf(arg, "re x%dy%d", i, j) == 2 ){
		if( !game )
			return notify_fail("��Ϸ��û��ʼ�أ��� mine start ��ʼ��\n");
		if( i > x || i < 1 ) 
			return notify_fail("Xֵ̫���̫С�ˡ�\n");
		if( j > y || j < 1 ) 
			return notify_fail("Yֵ̫���̫С�ˡ�\n");
		tmp += "ѡ���� X"+i+"��Y"+j+" �ĵط�ȡ����־��\n";
		i--;
		j--;
		if( i < 0 ) i = 0;
		if( j < 0 ) j = 0;
		if( map[i][j] != 11 )
			return notify_fail("���ز����ױ꣬�޷�ȡ����\n");
		map[i][j] = 0;
		mine--;
		if( game[i][j] == 9 )
			real_mine--;
		tmp += drew_map(0);
	}
	else return notify_fail("ָ���ʽ��mine <dig|at|re x?y?> | start | cancel | finish ��\n");
	tell_room(this_object(), tmp+"\n");
	return 1;
}

int valid_leave(object me, string dir)
{
  	if( me->query("id") == player )
               return notify_fail("��������Ϸ����Ҫ�뿪�����ȴ� mine cancel \n");

      	return ::valid_leave(me, dir);
} 
