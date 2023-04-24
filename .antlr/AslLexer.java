// Generated from /home/drosenberg/University/UPC Exchange Semester/CL-lab/practica/asl/Asl.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class AslLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, ASSIGN=4, PLUS=5, SUB=6, MUL=7, DIV=8, MOD=9, 
		VAR=10, ARRAY=11, INT=12, FLOAT=13, CHAR=14, BOOL=15, EQ=16, NEQ=17, G=18, 
		GE=19, L=20, LE=21, AND=22, NOT=23, OR=24, INTVAL=25, FLOATVAL=26, BOOLVAL=27, 
		CHARVAL=28, IF=29, THEN=30, ELSE=31, ENDIF=32, FUNC=33, ENDFUNC=34, READ=35, 
		WRITE=36, WHILE=37, DO=38, ENDWHILE=39, RETURN=40, ID=41, STRING=42, COMMENT=43, 
		WS=44, LPAR=45, RPAR=46, SEMICOLON=47, COLON=48, COMMA=49;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", 
			"VAR", "ARRAY", "INT", "FLOAT", "CHAR", "BOOL", "EQ", "NEQ", "G", "GE", 
			"L", "LE", "AND", "NOT", "OR", "INTVAL", "FLOATVAL", "BOOLVAL", "CHARVAL", 
			"IF", "THEN", "ELSE", "ENDIF", "FUNC", "ENDFUNC", "READ", "WRITE", "WHILE", 
			"DO", "ENDWHILE", "RETURN", "ID", "STRING", "ESC_SEQ", "COMMENT", "WS", 
			"LPAR", "RPAR", "SEMICOLON", "COLON", "COMMA"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'['", "']'", "'of'", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", 
			"'var'", "'array'", "'int'", "'float'", "'char'", "'bool'", "'=='", "'!='", 
			"'>'", "'>='", "'<'", "'<='", "'and'", "'not'", "'or'", null, null, null, 
			null, "'if'", "'then'", "'else'", "'endif'", "'func'", "'endfunc'", "'read'", 
			"'write'", "'while'", "'do'", "'endwhile'", "'return'", null, null, null, 
			null, "'('", "')'", "';'", "':'", "','"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, "ASSIGN", "PLUS", "SUB", "MUL", "DIV", "MOD", 
			"VAR", "ARRAY", "INT", "FLOAT", "CHAR", "BOOL", "EQ", "NEQ", "G", "GE", 
			"L", "LE", "AND", "NOT", "OR", "INTVAL", "FLOATVAL", "BOOLVAL", "CHARVAL", 
			"IF", "THEN", "ELSE", "ENDIF", "FUNC", "ENDFUNC", "READ", "WRITE", "WHILE", 
			"DO", "ENDWHILE", "RETURN", "ID", "STRING", "COMMENT", "WS", "LPAR", 
			"RPAR", "SEMICOLON", "COLON", "COMMA"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public AslLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Asl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\63\u014b\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\3\2"+
		"\3\2\3\3\3\3\3\4\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3"+
		"\n\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\r\3\16\3"+
		"\16\3\16\3\16\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3"+
		"\20\3\21\3\21\3\21\3\22\3\22\3\22\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3"+
		"\26\3\26\3\26\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3"+
		"\32\6\32\u00b5\n\32\r\32\16\32\u00b6\3\33\6\33\u00ba\n\33\r\33\16\33\u00bb"+
		"\3\33\3\33\6\33\u00c0\n\33\r\33\16\33\u00c1\3\34\3\34\3\34\3\34\3\34\3"+
		"\34\3\34\3\34\3\34\5\34\u00cd\n\34\3\35\3\35\3\35\3\35\3\36\3\36\3\36"+
		"\3\37\3\37\3\37\3\37\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3\"\3\"\3\""+
		"\3\"\3\"\3#\3#\3#\3#\3#\3#\3#\3#\3$\3$\3$\3$\3$\3%\3%\3%\3%\3%\3%\3&\3"+
		"&\3&\3&\3&\3&\3\'\3\'\3\'\3(\3(\3(\3(\3(\3(\3(\3(\3(\3)\3)\3)\3)\3)\3"+
		")\3)\3*\3*\7*\u0119\n*\f*\16*\u011c\13*\3+\3+\3+\7+\u0121\n+\f+\16+\u0124"+
		"\13+\3+\3+\3,\3,\3,\3-\3-\3-\3-\7-\u012f\n-\f-\16-\u0132\13-\3-\5-\u0135"+
		"\n-\3-\3-\3-\3-\3.\6.\u013c\n.\r.\16.\u013d\3.\3.\3/\3/\3\60\3\60\3\61"+
		"\3\61\3\62\3\62\3\63\3\63\2\2\64\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23"+
		"\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31"+
		"\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S+U,W\2Y-[.]/"+
		"_\60a\61c\62e\63\3\2\t\7\2\"\"\62;C\\aac|\4\2C\\c|\6\2\62;C\\aac|\4\2"+
		"$$^^\n\2$$))^^ddhhppttvv\4\2\f\f\17\17\5\2\13\f\17\17\"\"\2\u0153\2\3"+
		"\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2"+
		"\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31"+
		"\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2"+
		"\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2"+
		"\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2"+
		"\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2"+
		"I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3"+
		"\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2"+
		"\2\2e\3\2\2\2\3g\3\2\2\2\5i\3\2\2\2\7k\3\2\2\2\tn\3\2\2\2\13p\3\2\2\2"+
		"\rr\3\2\2\2\17t\3\2\2\2\21v\3\2\2\2\23x\3\2\2\2\25z\3\2\2\2\27~\3\2\2"+
		"\2\31\u0084\3\2\2\2\33\u0088\3\2\2\2\35\u008e\3\2\2\2\37\u0093\3\2\2\2"+
		"!\u0098\3\2\2\2#\u009b\3\2\2\2%\u009e\3\2\2\2\'\u00a0\3\2\2\2)\u00a3\3"+
		"\2\2\2+\u00a5\3\2\2\2-\u00a8\3\2\2\2/\u00ac\3\2\2\2\61\u00b0\3\2\2\2\63"+
		"\u00b4\3\2\2\2\65\u00b9\3\2\2\2\67\u00cc\3\2\2\29\u00ce\3\2\2\2;\u00d2"+
		"\3\2\2\2=\u00d5\3\2\2\2?\u00da\3\2\2\2A\u00df\3\2\2\2C\u00e5\3\2\2\2E"+
		"\u00ea\3\2\2\2G\u00f2\3\2\2\2I\u00f7\3\2\2\2K\u00fd\3\2\2\2M\u0103\3\2"+
		"\2\2O\u0106\3\2\2\2Q\u010f\3\2\2\2S\u0116\3\2\2\2U\u011d\3\2\2\2W\u0127"+
		"\3\2\2\2Y\u012a\3\2\2\2[\u013b\3\2\2\2]\u0141\3\2\2\2_\u0143\3\2\2\2a"+
		"\u0145\3\2\2\2c\u0147\3\2\2\2e\u0149\3\2\2\2gh\7]\2\2h\4\3\2\2\2ij\7_"+
		"\2\2j\6\3\2\2\2kl\7q\2\2lm\7h\2\2m\b\3\2\2\2no\7?\2\2o\n\3\2\2\2pq\7-"+
		"\2\2q\f\3\2\2\2rs\7/\2\2s\16\3\2\2\2tu\7,\2\2u\20\3\2\2\2vw\7\61\2\2w"+
		"\22\3\2\2\2xy\7\'\2\2y\24\3\2\2\2z{\7x\2\2{|\7c\2\2|}\7t\2\2}\26\3\2\2"+
		"\2~\177\7c\2\2\177\u0080\7t\2\2\u0080\u0081\7t\2\2\u0081\u0082\7c\2\2"+
		"\u0082\u0083\7{\2\2\u0083\30\3\2\2\2\u0084\u0085\7k\2\2\u0085\u0086\7"+
		"p\2\2\u0086\u0087\7v\2\2\u0087\32\3\2\2\2\u0088\u0089\7h\2\2\u0089\u008a"+
		"\7n\2\2\u008a\u008b\7q\2\2\u008b\u008c\7c\2\2\u008c\u008d\7v\2\2\u008d"+
		"\34\3\2\2\2\u008e\u008f\7e\2\2\u008f\u0090\7j\2\2\u0090\u0091\7c\2\2\u0091"+
		"\u0092\7t\2\2\u0092\36\3\2\2\2\u0093\u0094\7d\2\2\u0094\u0095\7q\2\2\u0095"+
		"\u0096\7q\2\2\u0096\u0097\7n\2\2\u0097 \3\2\2\2\u0098\u0099\7?\2\2\u0099"+
		"\u009a\7?\2\2\u009a\"\3\2\2\2\u009b\u009c\7#\2\2\u009c\u009d\7?\2\2\u009d"+
		"$\3\2\2\2\u009e\u009f\7@\2\2\u009f&\3\2\2\2\u00a0\u00a1\7@\2\2\u00a1\u00a2"+
		"\7?\2\2\u00a2(\3\2\2\2\u00a3\u00a4\7>\2\2\u00a4*\3\2\2\2\u00a5\u00a6\7"+
		">\2\2\u00a6\u00a7\7?\2\2\u00a7,\3\2\2\2\u00a8\u00a9\7c\2\2\u00a9\u00aa"+
		"\7p\2\2\u00aa\u00ab\7f\2\2\u00ab.\3\2\2\2\u00ac\u00ad\7p\2\2\u00ad\u00ae"+
		"\7q\2\2\u00ae\u00af\7v\2\2\u00af\60\3\2\2\2\u00b0\u00b1\7q\2\2\u00b1\u00b2"+
		"\7t\2\2\u00b2\62\3\2\2\2\u00b3\u00b5\4\62;\2\u00b4\u00b3\3\2\2\2\u00b5"+
		"\u00b6\3\2\2\2\u00b6\u00b4\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7\64\3\2\2"+
		"\2\u00b8\u00ba\4\62;\2\u00b9\u00b8\3\2\2\2\u00ba\u00bb\3\2\2\2\u00bb\u00b9"+
		"\3\2\2\2\u00bb\u00bc\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd\u00bf\7\60\2\2"+
		"\u00be\u00c0\4\62;\2\u00bf\u00be\3\2\2\2\u00c0\u00c1\3\2\2\2\u00c1\u00bf"+
		"\3\2\2\2\u00c1\u00c2\3\2\2\2\u00c2\66\3\2\2\2\u00c3\u00c4\7v\2\2\u00c4"+
		"\u00c5\7t\2\2\u00c5\u00c6\7w\2\2\u00c6\u00cd\7g\2\2\u00c7\u00c8\7h\2\2"+
		"\u00c8\u00c9\7c\2\2\u00c9\u00ca\7n\2\2\u00ca\u00cb\7u\2\2\u00cb\u00cd"+
		"\7g\2\2\u00cc\u00c3\3\2\2\2\u00cc\u00c7\3\2\2\2\u00cd8\3\2\2\2\u00ce\u00cf"+
		"\7)\2\2\u00cf\u00d0\t\2\2\2\u00d0\u00d1\7)\2\2\u00d1:\3\2\2\2\u00d2\u00d3"+
		"\7k\2\2\u00d3\u00d4\7h\2\2\u00d4<\3\2\2\2\u00d5\u00d6\7v\2\2\u00d6\u00d7"+
		"\7j\2\2\u00d7\u00d8\7g\2\2\u00d8\u00d9\7p\2\2\u00d9>\3\2\2\2\u00da\u00db"+
		"\7g\2\2\u00db\u00dc\7n\2\2\u00dc\u00dd\7u\2\2\u00dd\u00de\7g\2\2\u00de"+
		"@\3\2\2\2\u00df\u00e0\7g\2\2\u00e0\u00e1\7p\2\2\u00e1\u00e2\7f\2\2\u00e2"+
		"\u00e3\7k\2\2\u00e3\u00e4\7h\2\2\u00e4B\3\2\2\2\u00e5\u00e6\7h\2\2\u00e6"+
		"\u00e7\7w\2\2\u00e7\u00e8\7p\2\2\u00e8\u00e9\7e\2\2\u00e9D\3\2\2\2\u00ea"+
		"\u00eb\7g\2\2\u00eb\u00ec\7p\2\2\u00ec\u00ed\7f\2\2\u00ed\u00ee\7h\2\2"+
		"\u00ee\u00ef\7w\2\2\u00ef\u00f0\7p\2\2\u00f0\u00f1\7e\2\2\u00f1F\3\2\2"+
		"\2\u00f2\u00f3\7t\2\2\u00f3\u00f4\7g\2\2\u00f4\u00f5\7c\2\2\u00f5\u00f6"+
		"\7f\2\2\u00f6H\3\2\2\2\u00f7\u00f8\7y\2\2\u00f8\u00f9\7t\2\2\u00f9\u00fa"+
		"\7k\2\2\u00fa\u00fb\7v\2\2\u00fb\u00fc\7g\2\2\u00fcJ\3\2\2\2\u00fd\u00fe"+
		"\7y\2\2\u00fe\u00ff\7j\2\2\u00ff\u0100\7k\2\2\u0100\u0101\7n\2\2\u0101"+
		"\u0102\7g\2\2\u0102L\3\2\2\2\u0103\u0104\7f\2\2\u0104\u0105\7q\2\2\u0105"+
		"N\3\2\2\2\u0106\u0107\7g\2\2\u0107\u0108\7p\2\2\u0108\u0109\7f\2\2\u0109"+
		"\u010a\7y\2\2\u010a\u010b\7j\2\2\u010b\u010c\7k\2\2\u010c\u010d\7n\2\2"+
		"\u010d\u010e\7g\2\2\u010eP\3\2\2\2\u010f\u0110\7t\2\2\u0110\u0111\7g\2"+
		"\2\u0111\u0112\7v\2\2\u0112\u0113\7w\2\2\u0113\u0114\7t\2\2\u0114\u0115"+
		"\7p\2\2\u0115R\3\2\2\2\u0116\u011a\t\3\2\2\u0117\u0119\t\4\2\2\u0118\u0117"+
		"\3\2\2\2\u0119\u011c\3\2\2\2\u011a\u0118\3\2\2\2\u011a\u011b\3\2\2\2\u011b"+
		"T\3\2\2\2\u011c\u011a\3\2\2\2\u011d\u0122\7$\2\2\u011e\u0121\5W,\2\u011f"+
		"\u0121\n\5\2\2\u0120\u011e\3\2\2\2\u0120\u011f\3\2\2\2\u0121\u0124\3\2"+
		"\2\2\u0122\u0120\3\2\2\2\u0122\u0123\3\2\2\2\u0123\u0125\3\2\2\2\u0124"+
		"\u0122\3\2\2\2\u0125\u0126\7$\2\2\u0126V\3\2\2\2\u0127\u0128\7^\2\2\u0128"+
		"\u0129\t\6\2\2\u0129X\3\2\2\2\u012a\u012b\7\61\2\2\u012b\u012c\7\61\2"+
		"\2\u012c\u0130\3\2\2\2\u012d\u012f\n\7\2\2\u012e\u012d\3\2\2\2\u012f\u0132"+
		"\3\2\2\2\u0130\u012e\3\2\2\2\u0130\u0131\3\2\2\2\u0131\u0134\3\2\2\2\u0132"+
		"\u0130\3\2\2\2\u0133\u0135\7\17\2\2\u0134\u0133\3\2\2\2\u0134\u0135\3"+
		"\2\2\2\u0135\u0136\3\2\2\2\u0136\u0137\7\f\2\2\u0137\u0138\3\2\2\2\u0138"+
		"\u0139\b-\2\2\u0139Z\3\2\2\2\u013a\u013c\t\b\2\2\u013b\u013a\3\2\2\2\u013c"+
		"\u013d\3\2\2\2\u013d\u013b\3\2\2\2\u013d\u013e\3\2\2\2\u013e\u013f\3\2"+
		"\2\2\u013f\u0140\b.\2\2\u0140\\\3\2\2\2\u0141\u0142\7*\2\2\u0142^\3\2"+
		"\2\2\u0143\u0144\7+\2\2\u0144`\3\2\2\2\u0145\u0146\7=\2\2\u0146b\3\2\2"+
		"\2\u0147\u0148\7<\2\2\u0148d\3\2\2\2\u0149\u014a\7.\2\2\u014af\3\2\2\2"+
		"\r\2\u00b6\u00bb\u00c1\u00cc\u011a\u0120\u0122\u0130\u0134\u013d\3\b\2"+
		"\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}