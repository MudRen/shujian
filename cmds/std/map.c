// map.c
// Created by mxzhao 2003/11/28

/*********************************************
// ��ͼʾ��
<area>
<id>changle</id>
<name>���ְ�</name>
<byname>����,cl</byname>
<map>
������������������������������������������������������������������������������������������������������������������

                                      ����  ����ʯ��
                                       |     |
                               ˯��   С������԰���˽�ͤ
                                |      |
         ������������������  �����ȩ����ȩ������ȩ�������
         �������ݡ��������    |      |      |       |
         ������������������   ��   ����   С��    ����
                    \                  |
                  �����              ����
                      \                |
                     ��ʯ·������������ʯ·

������������������������������������������������������������������������������������������������������������������
</map>
<npc place=����>��ɽ��</npc>
<npc place=����>�³�֮</npc>
<npc place=С��>����ʯ,�׺�Ұ</npc>
<npc place=ʯ��>չ��</npc>
</area>
*********************************************/
inherit F_SAVE;
inherit F_CLEAN_UP;

#include <ansi.h>
#include <mudlib.h>
#include <get_place.h>



#define TAG_AREA			"area"
#define TAG_ID				"id"
#define TAG_NAME			"name"
#define TAG_BYNAME			"byname"
#define TAG_MAP				"map"
#define TAG_NPC				"npc"
#define KEY_PLACE			"place"

#define NEXT				"next"
#define MAP_FILE			DATA_DIR + "map"

#define MAP_TITLE(name)		HIY "��" + name + "��ͼ��" NOR  "����"HBRED+HIY"������"NOR"��ʾ�����ڷ���λ�ã�" + HBBLU + HIW +"������"NOR"��ʾĿ��Npcλ��"
#define NPC_TITLE(name)		HIY "��" + name + "��ҪNPC���¡�" NOR "\n"

#define MAP_LINE			repeat_string("��", 40) + "\n" 

#define THIS_ROOM_COLOR		HBRED + HIY
#define TARGET_ROOM_COLOR	HBBLU + HIW

#define LEGAL_COPYRIGHT		"\n	Copyright 1997-2003 ShuJian MUD Wizard Group.\n"

mapping maps;

int help(object me);

string query_save_file()
{
	return MAP_FILE;
}

private string color_filter(string content)
{
	if ( !content )
	{
		return "";
	}
	
	{
		mapping color_map = ([
			// Foreground Colors
			"$BLK$": BLK,		// Black
			"$RED$": RED, 		// Red 
			"$GRN$": GRN, 		// Green
			"$YEL$": YEL, 		// Yellow
			"$BLU$": BLU, 		// Blue  
			"$MAG$": MAG, 		// Magenta
			"$CYN$": CYN, 		// Cyan 
			"$WHT$": WHT, 		// White
			
			// Hi Intensity Foreground Colors
			"$HIR$": HIR, 		// Red
			"$HIG$": HIG, 		// Green
			"$HIY$": HIY, 		// Yellow
			"$HIB$": HIB, 		// Blue
			"$HIM$": HIM, 		// Magenta
			"$HIC$": HIC, 		// Cyan 
			"$HIW$": HIW, 		// White
			
			// Background Colors  
			"$BBLK$": BBLK, 	// Black
			"$BRED$": BRED, 	// Red
			"$BGRN$": BGRN, 	// Green
			"$BYEL$": BYEL, 	// Yellow
			"$BBLU$": BBLU, 	// Blue
			"$BMAG$": BMAG, 	// Magenta
			"$BCYN$": BCYN, 	// Cyan
			
			// Hi Intensity Background Colors  
			"$HBRED$": HBRED, 	// Red
			"$HBGRN$": HBGRN, 	// Green
			"$HBYEL$": HBYEL, 	// Yellow
			"$HBBLU$": HBBLU, 	// Blue
			"$HBMAG$": HBMAG, 	// Magenta
			"$HBCYN$": HBCYN, 	// Cyan
			
			// Puts everything back to normal
			"$NOR$": NOR, 		
			
			// Additional  
			"$U$": U, 			// Initialize underscore mode
			"$BLINK$": BLINK, 	// Initialize blink mode
			"$REV$": REV, 		// Turns reverse video mode on
			"$HIREV$": HIREV, 	// Hi intensity reverse video 
			"$BOLD$": BOLD, 	// Turn on bold mode
			]);
		
		foreach ( string color in keys(color_map) )
		{
			content = replace_string(content, color, color_map[color]);
		}
	}

	return content;
}

private int load_map()
{
	if ( !mapp(maps) )
	{
		restore();
	}
	
	if( !mapp(maps) || sizeof(maps) == 0 )
	{
		maps = ([]);
	}

	return 0;
}

// ����ַ������ض��ַ�
private string trim_string(string str)
{
	string *chs = ({" ", "\t", "\n"});

	foreach ( string ch in chs )
	{
		str = replace_string(str, ch, "");
	}

	return str;
}

// ���ַ�����ȡ��ָ������
private varargs mapping get_string(string str, string tag, string key)
{
	mapping result = ([]);
	string *substrs = ({ "", "", "" });

	if ( !str || sizeof(str) == 0 
		|| !tag || sizeof(tag) == 0 )
	{
		return 0;
	}

	if ( sscanf(str, "%*s<" + tag + "%s>%s</" + tag + ">%s", 
		substrs[0], substrs[1], substrs[2] ) != 4 )
	{
		return 0;
	}

	if ( !key || sizeof(key) == 0 )
	{
		if ( sizeof(trim_string(substrs[0])) != 0 )
		{
			return 0;
		}

		result[tag] = substrs[1];
	}
	else
	{
		foreach ( string kv in explode(substrs[0], " ") )
		{
			string value;
			if (sscanf(trim_string(kv), key + "%s=%s", kv, value) == 2)
			{
				if ( sizeof(trim_string(kv)) != 0 )
				{
					return 0;
				}

				result[tag] = ([ value:substrs[1] ]);

				break;
			}
		}

		if ( undefinedp(result[tag]) )
		{
			return 0;
		}
	}

	result[NEXT] = substrs[2];

	return result;
}

// ������ͼ�ļ�
int build_maps(object me, string arg)
{
	mapping temp;
	string str;
	int count = 0;

	if ( !arg )
	{
		return help(me);
	}

	if ( !wizardp(me) || wiz_level(me) < 4 )
	{
		return help(me);
	}
	
	str = read_file(resolve_path(me->query("cwd"), arg));
	
	if ( !str )
	{
		write("û������ļ���\n");
		return 1;
	}
	
	while ( temp=get_string(str, TAG_AREA) )
	{
		mapping map = ([]);
		mapping temp1;
		mapping temp2;
		
		str = temp[TAG_AREA];
		
		if ( temp1 = get_string(str, TAG_NAME) )
		{
			map[TAG_NAME] = temp1[TAG_NAME];
		}
		
		if ( temp1 = get_string(str, TAG_BYNAME) )
		{
			map[TAG_BYNAME] = explode(trim_string(temp1[TAG_BYNAME]), ",");
		}
		
		if ( temp1 = get_string(str, TAG_MAP) )
		{
			map[TAG_MAP] = temp1[TAG_MAP];
		}
		else
		{
			continue;
		}
		
		map[TAG_NPC] = ([]);

		while ( temp2 = get_string(str, TAG_NPC, KEY_PLACE) )
		{
			string place = keys(temp2[TAG_NPC])[0];

			if ( !place )
			{
				continue;
			}

			if ( undefinedp(map[TAG_NPC][place]) )
			{
				map[TAG_NPC][place] = ({});
			}

			map[TAG_NPC][place] += explode(trim_string(temp2[TAG_NPC][place]), ",");
			
			str = temp2[NEXT];
		}
		
		maps[get_string(temp[TAG_AREA], TAG_ID)[TAG_ID]] = map;

		str = temp[NEXT];

		count++;
	}

	save();

	write(sprintf("%d����ͼ�����ɹ���\n", count));
	
	return 1;
}

// Ŀǰ�ṩ�ĵ�ͼ�б�
int do_map_list(object me)
{
	string str = "";
	int i = 0;

	load_map();

	if ( !mapp(maps) || sizeof(maps) == 0 )
	{
		write(CHINESE_MUD_NAME + "Ŀǰû���ṩ�κε�ͼ��\n");
		return 1;
	}

	foreach ( string map in sort_array(keys(maps), 0) )
	{
		i++;

		str += sprintf("%-20s%s", maps[map][TAG_NAME] + "(" + map + ")", (i%4==0)?"\n":"");
	}

	write (CHINESE_MUD_NAME + "Ŀǰ�ṩ�ĵ�ͼ���£�\n" + str + "\n");

	return 1;
}

// ָ�������NPC�б�
int do_npc_list(object me, string area)
{
	string str = "";

	load_map();

	if ( !mapp(maps) || sizeof(maps) == 0 )
	{
		write(CHINESE_MUD_NAME + "Ŀǰû���ṩ�κε�ͼ��\n");
		return 1;
	}

	foreach ( string place in sort_array(keys(maps[area][TAG_NPC]), 0) )
	{
		str += sprintf("  %-12s��%-s\n", place, 
			implode(maps[area][TAG_NPC][place], "��"));
	}
	
	if ( sizeof(str) > 0 )
	{
		str = NPC_TITLE(maps[area][TAG_NAME]) + MAP_LINE + str + MAP_LINE;
		
		if (me->query("env/fastread") && sizeof(str) <= 8192)
		{
			write(str + "\n");
		}
		else
		{
			me->start_more(str + "\n");
		}
	}
	
	return 1;
}

void create()
{
	seteuid(getuid());

	load_map();
}

int main(object me, string arg)
{
	string area;
	string target;
	string file;
	string myarea;
	string str;
	string *paths;

	int npclist = 0;

	if ( me != this_player(1))
	{
		return 0;
	}

	if( !arg || arg=="" || arg=="here" )
	{
		area = "here";
	}
	else if ( arg == "-l" )
	{
		return do_map_list(me);
	}
	else if ( arg == "-t" )
	{
		area = "here";
		npclist = 1;
	}
	else if ( sscanf(arg, "%s -t %s", area, target)==2 )
	{
	}
	else if ( sscanf(arg, "%s -t", area)==1 )
	{
		npclist = 1;
	}
	else if ( sscanf(arg, "-t %s", target)==1 )
	{
	}
	else if ( sscanf(arg, "-update %s", file)==1 )
	{
		return build_maps(me, file);
	}
	else
	{
		if ( !area ) 
		{
			area = arg;
		}
	}
	
	if ( !area )
	{
		area = "here";
	}
	
	paths = explode(base_name(environment(me)), "/");

	if (sizeof(paths) > 1)
	{
		myarea = paths[sizeof(paths)-2];
	}

	if ( area == "here" )
	{
		area = myarea;
	}
	
	if ( undefinedp(maps[area]) )
	{
		foreach ( string map in keys(maps) )
		{
			if ( maps[map][TAG_NAME] == area 
				|| member_array(area, maps[map][TAG_BYNAME]) >=0 )
			{
				area = map;
				break;
			}
		}
		
		if ( undefinedp(maps[area]) )
		{
			return notify_fail(CHINESE_MUD_NAME + "Ŀǰû���ṩ������ĵ�ͼ��\n");
		}
	}
	
	if (npclist)
	{
		return do_npc_list(me, area);
	}
	
	if ( undefinedp(maps[area][TAG_MAP]) )
	{
		return notify_fail(CHINESE_MUD_NAME + "������ĵ�ͼ�쳣��\n");
	}
	
	str = maps[area][TAG_MAP];
	
	if ( area == myarea )
	{
		string roomname = strip(environment(me)->query("short"));
		str = replace_string(str, roomname, THIS_ROOM_COLOR + roomname + NOR);
	}
	
	if ( target && sizeof(target) > 0)
	{
		foreach ( string place in keys(maps[area][TAG_NPC]) )
		{
			if ( member_array(target, maps[area][TAG_NPC][place]) >=0 )
			{
				str = replace_string(str, place, TARGET_ROOM_COLOR + place + NOR);
				break;
			}
		}

		str = replace_string(str, target, TARGET_ROOM_COLOR + target + NOR);
	}
	
	str = MAP_TITLE(maps[area][TAG_NAME]) + str;
	
	if (me->query("env/fastread") && sizeof(str) <= 8192)
	{
		write(str + "\n");
	}
	else
	{
		me->start_more(str + "\n");
	}
	
	return 1;
}

int help(object me)
{
	string help = @HELP
ָ��˵����
	���ָ���������鿴���ڵ���ĵ�ͼ��NPC�����

ָ���ʽ��map [������| here] [-t [Ŀ����]> | -l]

	map                     ��ʾ��ǰ��������ĵ�ͼ
	map -l                  ��ʾ���е�ͼ�б�
	map [here] -t           ��ʾ��ǰ���������NPC�б�
	map [here] -t Ŀ����    ������ʾ��ǰ�����ڴ�Ŀ�귿��
	map ������              ��ʾָ������ĵ�ͼ
	map ������ -t           ��ʾָ�������NPC�б�
	map ������ -t Ŀ����    ������ʾָ�������ڴ�Ŀ�귿��

	���������� map -l �鿴��Ŀ��������

HELP;

	help += "\t" THIS_ROOM_COLOR "��ǰ���ڷ���" NOR "\t" TARGET_ROOM_COLOR "Ŀ�귿��" NOR "\n\n";
	if ( wizardp(me) )
	{
		help += @HELP
	map -update �ļ���      ���ļ���ĵ�ͼ��Ϣ���µ�ͼ
HELP;
	}

	help += LEGAL_COPYRIGHT;

	write(help);

    return 1;
}
